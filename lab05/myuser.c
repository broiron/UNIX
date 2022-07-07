#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  struct passwd *buf; //구조체 -> 
  char *name;
  char *realname;
  __uid_t uid;
  __gid_t gid;
  char *hdir;
  char *shellp;
  
  if((buf = getpwnam(argv[1]))==NULL){
    fprintf(stderr,"%s: unknown user\n", argv[1]);
    exit(1);}
  
  name = buf->pw_name;
  uid = buf->pw_uid;
  gid = buf->pw_gid;
  realname = buf->pw_gecos;
  hdir = buf->pw_dir;
  shellp = buf->pw_shell;

  printf("%s, %d, %d, %s, %s, %s\n", name, uid, gid, realname, hdir, shellp);
  
}
