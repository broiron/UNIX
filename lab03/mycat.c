#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#define BUFFSIZE 4096

char buf[BUFFSIZE];

int main(int argc, char *argv[])
{
  int fd, check;

  fd = open(argv[1], O_RDONLY);
  if (fd == -1){
    perror("open");
    exit(1);}
    
    check = read(fd, buf, BUFFSIZE);
    if (check == -1){
      perror("read");}
    
  puts(buf);
  close(fd);
  exit(0);
}
