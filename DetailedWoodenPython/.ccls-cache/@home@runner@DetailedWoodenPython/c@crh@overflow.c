#include <stdio.h>

int main() {
  int array[4];
  int i;
  for (i = 0; i < 100; i++) {
    array[i] = i;
    printf("Set array[%d]=%d\n", i);
  }
  return 0;
}