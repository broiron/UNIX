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
  uid_t uid; gid_t gid;
  off_t size;
  char *path;
  char file_type = '\0';
  
  for(i=1; i<argc; i++){
    path = argv[i];
    if(lstat(path, &buf) == -1){
      perror("lstat");
      exit(1);}
    mode = buf.st_mode & 07777;
    uid = buf.st_uid; gid = buf.st_gid;
    size = buf.st_size;

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
 
    printf("%c %05o %4d %4d %8ld %s\n", file_type, mode, uid, gid, size, path);
  }
  
  return 0;
}
