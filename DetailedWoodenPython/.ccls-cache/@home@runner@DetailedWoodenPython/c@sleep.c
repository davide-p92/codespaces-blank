#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>
#include <string.h>


static int sigflag;

//https://www.gnu.org/software/libc/manual/html_node/Sigaction-Function-Example.html
void sig_handler(int signum) {
  //check if jump flag is not 0
  if(sigflag == 0) return;
  printf("Received signal %d\n", signum);
  fflush(stdout);
}

void
termination_handler (int signum, siginfo_t *sinfo, void *context)
{
  //struct temp_file *p;
  
  
  printf("In term handler for SIGSEGV:\t"); 
  printf("signum=%d, si_uid=%d, si_pid=%d, si_status=%d, si_addr=%p, si_stime=%ld, si_utime=%ld\n", signum, sinfo->si_uid, sinfo->si_pid, sinfo->si_status, sinfo->si_addr, sinfo->si_stime, sinfo->si_utime);
  //fflush(stdout);
  //_exit(0);
}


int main(int argc, char *argv[]) {
  if(argc < 1 || argc > 2) {
    printf("Usage: %s <str>\n", argv[0]);
    return -1;
  }
  time_t times;
  struct timespec tout;
  struct tm *tmstruct;
  char buf[64];
  struct sigaction saction, oldaction;
  sigset_t procmask, newmask, oldmask;
  int sec_start, sec_for, sec_end;
  sec_start = time(&times);
  clock_gettime(CLOCK_REALTIME, &tout);
  tmstruct = localtime(&tout.tv_sec);
  strftime(buf, sizeof(buf), "%r", tmstruct);
  printf("curr time: %s\n", buf);
  char *ciao;
  if(signal(SIGQUIT, sig_handler) == SIG_ERR) {
    printf("could not catch SIGQUIT\n");
    return -1;
  }
  int i = 0;
  /*check SIGSEGV*/
  saction.sa_sigaction = termination_handler;
  sigemptyset(&saction.sa_mask);
  saction.sa_flags |= SA_SIGINFO | SA_ONSTACK; //To give termination_handler 3 args instead of one
  if(oldaction.sa_handler != SIG_IGN) {
    sigaction(SIGSEGV, &saction, NULL);
  }
  sprintf(ciao, "%s", argv[1]);
  /*block SIGQUIT and ssave current mask*/
  if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) == -1) {
    printf("could not block SIGQUIT\n");
    return -1;
  }
  if(sigpending(&procmask) < 0) {
    printf("could not get pending signals\n");
    return -1;
  }

  for(;;) {
    sleep(60);
    sec_for = time(&times) - sec_start;
    tmstruct = localtime(&times);
    if(sec_for % 300 == 0)
      printf("Time elapsed: %d\n", tmstruct->tm_sec);
  }
  return 0;
}
