/* UD4.LAB3.S2 - numero primo */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//#define THREADS_ON 0

long num;
//int primo = 1;

void *eprimo(void *n);
void eprimo1(long n);

int main(void) {

  
  clock_t start, end;
  pthread_t tid;
  pthread_attr_t tattr;
  /*childe process?*/
  pid_t childpid;
  pthread_attr_init(&tattr);
  
  double cpu_time_used;
  int threads_on ;
  
  start = clock();
  /*Input*/
  printf("Inserisci un numero intero:\n");
  scanf("%ld", &num);
  //getchar();
  printf("Vuoii usare threads? (s:1 n:0)\n");
  scanf("%d", &threads_on);
  long *t_val = (long *)malloc(sizeof(*t_val));
  *t_val = num;

  if(threads_on == 1) {
    pthread_create(&tid, &tattr, eprimo, t_val);
    pthread_join(tid, NULL);
  }
  
  
/*
  for (long i = 0; i < num; i++) {
    //childpid = fork(); 
    primo = eprimo(i);
    if (primo)
      printf("Il numero %d è primo\n", i);
    // else
    // printf("Il numero %d non è primo\n", i);
  }*/
  //free(t_val);
  /* Fine del programma */
  else {
    eprimo1(num);
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Tempo CPU usato: %lf\n", cpu_time_used);
  printf("\nProgramma terminato\n\n");
  return 0;
}

void *eprimo(void *param) {
  
  long n = *(long *)param;
  for(long i = 100000000; i < n; i++) {
    int primo = 1;
    for (long divisore = 2; divisore < i; divisore++) {
      //printf("n=%ld\n", i);
      if (i % divisore == 0) {
        primo = 0;
        break;
      }
    }
    if(primo == 1) printf("Il numero %ld è primo\n", i );
  }
  

  
  free(param);
  pthread_exit(0);
}

void eprimo1(long n) {

  for(long i = 100000000; i < n; i++) {
    int primo = 1;
    for (long divisore = 2; divisore < i; divisore++) {
      //printf("n=%ld\n", i);
      if (i % divisore == 0) {
        primo = 0;
        break;
      }
    }
    if(primo == 1) printf("Il numero %ld è primo\n", i);
  }
  return;
}