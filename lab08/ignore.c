#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
  int i;

  for(i=0; i<20; i++){
    if (signal(SIGINT, SIG_IGN)==SIG_ERR){
      perror("signal");
      exit(1);}
    printf("sleeping for 1 second...\n");
    sleep(1);   
  }
  return 0;
}
