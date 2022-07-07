#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int fd,  n;
  int check=0;
  char buf[1];
  char m;

  m = argv[2][0];
  
  fd=open(argv[1], O_RDONLY);

  if(fd==-1){
    perror("open");
    exit(1);}
  
  while ((n=read(fd, buf, 1))>0){
    if(m == buf[0]){
      check=check+1;
    }
  }
  if (n<0){
    perror("read");
    exit(1);}

  printf("%d\n", check);

  close(fd);
  exit(1);
    
  

  return 0;
}
