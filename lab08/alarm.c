#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler (int signo)
{
  exit(0);
}

int main(int argc, char *argv[])
{
  unsigned int sec;
  sec = atoi(argv[1]);
  
  alarm(sec);
  for (;;){
    printf("running...\n");
    sleep(1);
    if(signal(SIGALRM, handler)==SIG_ERR){
      perror("signal");
      exit(1);
    }
    
  }

  return 0;
}


