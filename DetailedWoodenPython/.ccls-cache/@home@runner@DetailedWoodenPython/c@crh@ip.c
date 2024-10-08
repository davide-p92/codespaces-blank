#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define B 256

void convert_to_bin(long long n) {
  char *sbin; // i bit dell'indiriz sono 32
  long long i = n;
  int r;
  size_t len = 0;
  sbin = (char *)malloc(33 * sizeof(int));
  sbin[0] = '\0';
  int k = 0;
  while (i > 0) {
    r = i % 2; // resto della divisione per due
    //sprintf(sbin, "%s%d", sbin, r);
    sbin[0] = r + '0';
    i = i / 2;
    //printf("%lld\n", i);
    len++;
    memmove(sbin + 1, sbin, len + 1);
    k++;
  }
  printf("%lld In numero binario: \n%s\n", n, sbin);
  free(sbin);
  return;
}

int main() {
  int o[4];
  for (int j = 0; j < 4; j++) {
    int num;
    printf("Inserire ottetto indiriz: \n");
    scanf("%d", &num);
    o[j] = num;
  }

  long long temp = 0;
  for (int i = 0; i < 4; i++) {
    printf("o[i]: %d\n", o[i]);
    temp = temp * B + o[i];
  }
  printf("0x%4llx\n", temp);
  int64_t temp1 = (int64_t)temp;
  char s[32];
  convert_to_bin(temp);
  /*printf(BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN"
   * "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN" "BYTE_TO_BINARY_PATTERN"
   * \n", BYTE_TO_BINARY(temp1<<32), BYTE_TO_BINARY(temp1<<24),
   * BYTE_TO_BINARY(temp1<<16), BYTE_TO_BINARY(temp1<<8),
   * BYTE_TO_BINARY(temp1));*/
  return 0;
}