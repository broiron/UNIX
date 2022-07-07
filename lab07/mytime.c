#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>

#define CLK_TCK sysconf(_SC_CLK_TCK)

int main(int argc, char *argv[])
{
  int pid;
  struct tms buf1, buf2;
  clock_t t1, t2;
  float pwd;

  t1 = times(&buf1);
  printf("parent:fork...\n");
  pid=fork();
  if(pid < 0){
    perror("fork");
    exit(1);}
  else if(pid == 0){
    printf("child: exec...\n");
    execvp(argv[1], &argv[1]);
    exit(0);}
  else {
    printf("parent: wait...\n");
    wait(NULL);
    printf("parent: exit...\n");
    t2 = times(&buf2);
    pwd = (double)(t2-t1)/CLK_TCK;
    printf("real:%.3f sec\n", pwd);
    pwd = (double) (buf2.tms_utime + buf2.tms_cutime)/CLK_TCK;
    printf("user:%.3f sec\n", pwd);
    pwd = (double) (buf2.tms_stime + buf2.tms_cstime)/CLK_TCK;
    printf("sys:%.3f sec\n", pwd);
    exit(0);
  }
}
