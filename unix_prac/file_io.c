#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define BUFFSIZE 4096

char buf[BUFFSIZE];

int main(int argc, char *argv[])
{
  int n, m, fd_real, fd_copy;

  fd_real = open(argv[1], O_RDONLY);
  fd_copy = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_EXCL, 0644);
  if (fd_real==-1 || fd_copy == -1){
    perror("open");
    exit(1);}

  while ((n=read(fd_real, buf, BUFFSIZE))>0){
    m = write(fd_copy, buf, BUFFSIZE);
    if (m != BUFFSIZE){
      perror("write");
      exit(1);}
  }
  if (n<0){
    perror("read");
    exit(1);}

  close(fd_real);
  close(fd_copy);

  exit(0);
}
