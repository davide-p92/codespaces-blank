#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTR 1024

// glob varabili
char stringa[MAXSTR];
int occorrenza;// = 0;

void *contalett(void *param);

int main() {
  printf("Inserisci una stringa (max 1024 caratteri):\n");
  /*stringa = */gets(stringa);
  getchar();
  char carattere;
  printf("Inserisci un carattere da ricercare: ");
  scanf("%c", &carattere);

  pthread_t t1;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&t1, &attr, contalett, &carattere);
  pthread_join(t1, NULL);
  printf("n: occ.: %d\n", occorrenza);
  return 0;
}

void *contalett(void *param) {
  char sottostringa[MAXSTR];
  strcpy(sottostringa, stringa);
  /*indice per strstr, indica dove trova carattere in sottostringa*/
  char *kptr;
  char *p;
  p = (char *) param;
  p = (char *)malloc(sizeof(char));
  while ((kptr = strstr(sottostringa, param)) != NULL) {
    printf("strstr da contalett\n");
    occorrenza++;
    *sottostringa = *(sottostringa + sizeof(sottostringa) - sizeof(kptr));
  }
  free(p);
  pthread_exit(0);
}
