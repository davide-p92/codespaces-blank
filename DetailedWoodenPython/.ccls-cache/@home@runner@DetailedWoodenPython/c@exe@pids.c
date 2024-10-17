#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid1, pid;
  pid = fork();
  if(pid<0) {
    printf("error fork\n");
    return -1;
  }
  else if(pid == 0) {
    //childe
    pid1 = getpid();
    printf("child: pid=%d\n", pid);
    printf("child: pid1=%d\n", pid1);
  } else {
    //parent
    pid1 = getpid();
    printf("parent: pid=%d\n", pid);
    printf("parent: pid1=%d\n", pid1);
    wait(NULL);
  }

  return 0;
  
}