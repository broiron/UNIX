#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
  struct stat buf;
  int i, n;
  time_t at, mt, ct;
  char *path;
  char buffer[100];
  struct tm *timeptr1, *timeptr2, *timeptr3;
  
  for(i=1; i<argc; i++){

    path=argv[i];

    if((n=lstat(path, &buf))==-1){
      perror("lstat");
      exit(1);}

    at = buf.st_atime;
    mt = buf.st_mtime;
    ct = buf.st_ctime;

    printf("At:%ld\nMt:%ld\nCT:%ld\n", at, mt, ct);

    timeptr1 = localtime(&at);
    timeptr2 = localtime(&mt);
    timeptr3 = localtime(&ct);

    strftime(buffer, 100, "Atime: %c    %j", timeptr1);
    printf("%s\n", buffer);
    strftime(buffer, 100, "Mtime: %c    %j", timeptr2);
    printf("%s\n", buffer);
    strftime(buffer, 100, "Ctime: %c    %j", timeptr3);
    printf("%s\n\n", buffer);
    
  }
  exit(0);
}

