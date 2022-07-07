#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  pid_t pid, ppid;

  pid = getpid();
  ppid = getppid();

  printf("pid=%d, ppid=%d\n", pid, ppid);

  return 0;
}
