/* Fibonacci.c */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX 1000

//variabile globale
int ar[MAX];

void *fibonacci(void *param) {
  int k = 0;
  
  int n = atoi(param);
  while (k <= n) {
    if (k == 0)
      ar[k] = 0;
    else if (k == 1 || k == 2) {
      ar[k] = 1;
    } else {
      ar[k] += ar[k - 1] + ar[k - 2];
    }
    k++;
  }
  pthread_exit(0);
}

int main() {
  int len;
  printf("Inserire lunghezza serie di Fibonacci: \n");
  scanf("%d", &len);
  if (len > MAX) {
    printf("Errore. lunghezza massima superata.\n");
  }
  //Threading
  pthread_t tid; //ID thr
  pthread_attr_t tattr;
  char lenc[3];
  sprintf(lenc, "%d", len);
  //default attr
  pthread_attr_init(&tattr);
  pthread_create(&tid, &tattr, fibonacci, lenc);
  pthread_join(tid, NULL);
  for (int i = 0; i < len; i++) {
    printf("%d\t", ar[i]);
  }
  printf("\n");
  return 0;
}