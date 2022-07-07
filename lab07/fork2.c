#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int glob = 6;

int main(void)
{
  pid_t pid;
  int loc = 88;

  printf("before fork\n");
  pid = fork();
  if(pid<0) {  //fork error
    perror("fork");
    exit(1);}
  else if(pid == 0){    //child
    glob++;
    loc++;
  }
  else {     //parent
    sleep(2);}
  printf("pid=%d, glob=%d, loc=%d\n", getpid(), glob, loc);
  
  return 0;
}
