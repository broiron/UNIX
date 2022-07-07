#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  int fd, length, i, n;
  off_t offset;
  
  if((fd = open(argv[1], O_WRONLY))==-1)
    {
      perror("open");
      exit(1);}

  length=atoi(argv[3]);

  if((offset=lseek(fd, 0, SEEK_END)==-1))
    {
      perror("lseek");
      exit(1);}
  for(i=0; i<length; i++){
    n=write(fd, argv[2], 1);
    if(n!=1){
      perror("write");
      exit(1);
    }
  }
    close(fd);
    exit(0);
}
  

  
