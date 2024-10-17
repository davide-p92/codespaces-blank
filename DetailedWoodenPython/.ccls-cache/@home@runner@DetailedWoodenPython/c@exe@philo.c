#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>


pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

enum {THINK, EAT} state[5];

void putdown(int i) {
  state[i] = THINK;
  
  printf("Sto mangiando\n");
}

typedef struct {
  
} philosopher[5];

