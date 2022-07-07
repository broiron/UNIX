#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  struct stat buf;
  int i;
  off_t size;
  char *path;

  for(i=1; i<argc; i++){
    path = argv[i];
    if(lstat(path, &buf) == -1){
      perror("lstat");
      exit(1);}
    size = buf.st_size;
    printf("%10ld %s\n", size, path);
  }
  

  return 0;
}
