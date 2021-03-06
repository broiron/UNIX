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
  uid_t uid; gid_t gid;
  char *path;
 
  for(i=1; i<argc; i++){
    path = argv[i];
    if(lstat(path, &buf) == -1){
      perror("lstat");
      exit(1);}
    uid =  buf.st_uid;
    gid = buf.st_gid;
    printf("%5d%5d %s\n", uid, gid, path);
  }
  
  return 0;
}
