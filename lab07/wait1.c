#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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
    sleep(60);
  }
  
}
