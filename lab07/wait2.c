#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
  pid_t pid;

  pid = fork();

  if (pid<0){
    perror("fork");
    exit(1);}
  else if(pid == 0){
    printf("child=%d\n", getpid());
  }
  else {
    printf("parent=%d\n", getpid());
    wait(NULL);
    sleep(60);
  }
}
