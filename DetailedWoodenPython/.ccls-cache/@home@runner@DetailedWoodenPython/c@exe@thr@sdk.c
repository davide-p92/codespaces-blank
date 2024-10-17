#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

typedef struct {
int row;
int column;
} parameters;

static int grid[9][9] = {{3,2,6,5,8,1,3,5,1}, 
                  {3,2,6,5,8,1,3,5,1},
                  {3,2,6,5,8,1,3,5,1},
                  {3,2,6,5,8,1,3,5,1},
  {3,2,6,5,8,1,3,5,1},
  {3,2,6,5,8,1,3,5,1},
  {3,2,6,5,8,1,3,5,1},
  {3,2,6,5,8,1,3,5,1},
  {3,2,6,5,8,1,3,5,1}};

void *check_rows(void *rw) {

  int okay = 0;
  int cols[9];
  parameters *data = (parameters *)malloc(sizeof(parameters));
  
  //controlla una rg
  data->row = rw;
  for(int cl = 0; cl < sizeof(grid[rw]) / sizeof(grid[rw][0]); cl++) {
    data->column = grid[rw][cl];
    cols[cl] = grid[rw][cl];
    
  }
  int cnt = 0; //conteggio numeri
  for(int j = 0; j < sizeof(cols) / sizeof(int); j++) {
    for(int k = sizeof(cols) / sizeof(int); k >= j; k--) {
      okay = 1;
      if(*(cols + k) == *(cols + j)) {
        cnt++;
        printf("no ok (rig, col) (%d, %d)\n", rw, j);
        break;
      }
    }

  }
  return 0;
}
void check_cols(int cl) {

  int okay = 0;
  int rows[9];
  parameters *data = (parameters *)malloc(sizeof(parameters));

  //controlla una rg
  data->column = cl;
  for(int row = 0; row < sizeof(grid[cl]) / sizeof(int); row++) {
    data->row = grid[row][cl];
    rows[row] = grid[row][cl];
  }
  int cnt = 0; //conteggio numeri
  for(int j = 0; j < sizeof(rows) / sizeof(int); j++) {
    for(int k = sizeof(rows) / sizeof(int); k >= j; k--) {
      okay = 1;
      if(*(rows + k) == *(rows + j)) {
        cnt++;
        printf("no ok (rig, col) (%d, %d)\n", j, cl);
        okay = 0;
        break;
      }
    }

  }
  //return 0;
}

int main(int argc, char **argv) {
  int tr, tc;
  pthread_t tid;
  for(int i = 0; i < sizeof(grid) / sizeof(int); i++) {
    tr = pthread_create(&tid, NULL, check_rows, i);
    if(tr != 0) {
      printf("err pthread_create: %s\n", strerror(errno));
    }
  }
  
}