#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
/*cmd senza args*/
#define CMD_LEN 50
/*cmd con variadic args*/
#define CMD_LEN_OPTS 256
/*dimens dell'oggetto shm*/
#define SHM_SZ 512
/*ns per confronto tra start e finish*/
#define NS_PER_SEC 1000000000

int main(int argc, char **argv) {
  char *cmd;
  switch (argc) {
  case 2:
    cmd = (char *)malloc(sizeof(char) * CMD_LEN);
    if (cmd == NULL) {
      printf("error malloc: %s\n", strerror(errno));
      return -1;
    }
    break;
  default:
    printf("uso: %s <cmd>\n", argv[0]);
    return 0;
    break;
  }
  struct timespec start_ts, finish_ts;
  time_t start, finish;
  pid_t pid;

  const char *name = "START"; // var salvata in sh_mem
  const char *namee = "END";

  if ((pid = fork()) < 0) {
    printf("error fork\n");
    return -1;
  }
  if (pid == 0) /*childe*/ {
    printf("entrato in child\n");
    clock_gettime(CLOCK_REALTIME, &start_ts);
    char *ptr;
    // usa shared memory per salvare il valore di time da child al parent
    int fds, fdf;
    fds = shm_open(name, O_CREAT | O_RDWR, 0666);
    /*inizial dimens*/
    if (ftruncate(fds, SHM_SZ) < 0) {
      printf("errore ftruncate su fds: %s\n", strerror(errno));
      return -1;
    }
    if ((ptr = (char *)mmap(0, SHM_SZ, PROT_READ | PROT_WRITE, MAP_SHARED, fds,
                            0)) < 0) {
      printf("errore mmap: %s\n", strerror(errno));
    }

    // scrivi sull'ogg shm
    /*memcpy(ptr,
           (char *)(start_ts.tv_sec * NS_PER_SEC + start_ts.tv_nsec),
           sizeof(unsigned long));
*/
    unsigned long result_start, result_finish;
    result_start = start_ts.tv_sec * NS_PER_SEC + start_ts.tv_nsec;
    sprintf(ptr, "%s",
            (char *)(result_start));
    printf("ptr: %s\n", ptr);
    ptr += strlen((char *)(result_start));
    printf("copiato in shm %lu %lu bytes\n",
           (unsigned long)(result_start),
           sizeof(unsigned long));
    // exe cmd, verifica error
    if (execl(argv[0], argv[1], (char *)NULL) == -1) {
      printf("errore execl: %s\n", strerror(errno));
      return -1;
    }
    clock_gettime(CLOCK_REALTIME, &finish_ts);
    // salva anche la ifne
    fdf = shm_open(namee, O_CREAT | O_RDWR, 0666);
    if (ftruncate(fdf, SHM_SZ) < 0) {
      printf("errore ftruncate su fdf: %s\n", strerror(errno));
      return -1;
    }
    if ((ptr = (char *)mmap(0, SHM_SZ, PROT_READ | PROT_WRITE, MAP_SHARED, fdf,
                            0)) < 0) {
      printf("err mmap fdf: %d\n", errno);
      return -1;
    }
    // stessa roba
    /*memcpy(ptr, (char *)(finish_ts.tv_sec * NS_PER_SEC + finish_ts.tv_nsec),
     * sizeof(unsigned long));
     */
    result_finish = finish_ts.tv_sec * NS_PER_SEC + finish_ts.tv_nsec;
    sprintf(ptr, "%s",
            (char *)(result_finish));
    ptr += strlen((char *)(result_finish));
    printf("copitato in shm %lu %lu bytes\n",
           (unsigned long)(result_finish),
           sizeof(unsigned long));
    // esce
    exit(1);
  } else { /*parent*/
    wait(&pid);
    int parfds, parfdf;
    char *parptrs, *parptre;
    parfds = shm_open(name, O_RDONLY, 0666);
    parfdf = shm_open(namee, O_RDONLY, 0666);
    if ((parptrs = (char *)mmap(0, SHM_SZ, PROT_READ | PROT_WRITE, MAP_SHARED,
                                parfds, 0)) < 0) {
      printf("errore partptrs mmset: %s\n", strerror(errno));
      return -1;
    }
    if ((parptre = (char *)mmap(0, SHM_SZ, PROT_READ | PROT_WRITE, MAP_SHARED,
                                parfdf, 0)) < 0) {
      printf("errore parptre mmset: %s\n", strerror(errno));
      return -1;
    }
    printf("parptrs: %ld\n", atol(parptrs));
    printf("parptre: %ld\n", atol(parptre));
    printf("tempo impiegato da cmd %s: %lu ns\n", cmd, parptre - parptrs);
    // libera memoria
    free(cmd);
    // stacca shm oggetti
    shm_unlink(name);
    shm_unlink(namee);
  }

  return 0;
}