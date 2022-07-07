#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler1(int signo)
{
  exit(0);
}
void handler2(int signo)
{
  sleep(1);
  printf("parent...\n");
}
void handler3(int signo)
{
  sleep(1);
  printf("child...\n");
}

int main(void)
{
  pid_t pid;
  pid_t ppid = getpid();
  pid = fork();
  if(pid<0){
    perror("fork");
    exit(1);}
  else if (pid==0){ //child process
    if(signal(SIGALRM, handler1)==SIG_ERR){
      perror("signal");
      exit(1);}
    alarm(10);
    if(signal(SIGUSR1, handler3)==SIG_ERR){
      perror("signal");
      exit(1);}
    while(1){
      if(kill(ppid, SIGUSR1)==-1){
	perror("kill");
	exit(1);}
      pause();
    }
      
  }
  else { //parent process
    if(signal(SIGALRM, handler1)==SIG_ERR){
      perror("signal");
      exit(1);}
    alarm(10);
    if(signal(SIGUSR1, handler2)==SIG_ERR){
      perror("signal");
      exit(1);}
    while(1){
      pause();
      if(kill(pid, SIGUSR1)==-1){
	perror("kill");
	exit(1);}
      }
  }
}
