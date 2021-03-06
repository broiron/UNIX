#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  struct stat buf;
  char file_type = '\0';
  int i;
  mode_t mode;
  char *path;
  
  for(i=1; i<argc; i++){
    path = argv[i];
    
    if (lstat(path, &buf)< 0){
      perror("Istat");
      exit(1);}

    mode = buf.st_mode;
    if(S_ISREG(mode)){
      file_type = '-';}
    else if (S_ISDIR(mode)){
      file_type = 'd';}
    else if (S_ISCHR(mode)){
      file_type = 'c';}
    else if (S_ISBLK(mode)){
      file_type = 'b';}
    else if (S_ISFIFO(mode)){
      file_type = 'p';}
    else if (S_ISSOCK(mode)){
      file_type = 's';}
    else if (S_ISLNK(mode)){
      file_type = 'I';}
    printf("%c %s\n", file_type, path);
  }
  
  return 0;
}
