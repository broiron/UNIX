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
  mode_t mode;
  char *path;

  for(i=1; i<argc; i++){
    path = argv[i];
    if(lstat(path, &buf) == -1){
      perror("lstat");
      exit(1);}
    mode = buf.st_mode & 07777;    

    printf("%05o %s\n", mode, path);
  }
  
    
  return 0;
}
