#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  char *pathname;
  int i;
  
  for (i=1; i<argc; i++){
    pathname = argv[i];
    if(unlink(pathname) == -1){
      perror("unlink");
      exit(1);}
  }
  
  return 0;
}
