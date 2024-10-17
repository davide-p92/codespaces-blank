#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

int main() {
  time_t times;
  struct tm *tmstruct;
  int sec_start, sec_for, sec_end;
  sec_start = time(&times);
  int i = 0;
  for(;;) {
    sleep(60);
    sec_for = time(&times) - sec_start;
    localtime_r(&times, tmstruct);
    if(sec_for % 300 == 0)
      printf("Time elapsed: %d\n", tmstruct->tm_sec);
  }
  return 0;
}