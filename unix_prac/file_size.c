#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  char *path;
  int fd;
  off_t fsize;
  
  path = argv[1];
  if ((fd=open(path, O_RDONLY))<0){
    perror("open");
    exit(1);
  }

  if ((fsize = lseek(fd, 0, SEEK_END))<0){
    fprintf(stderr, "lseek error\n");
    exit(1);
  }

  printf("The size of <%s? is %ld bytes.\n", path, fsize);
  exit(0);
}
