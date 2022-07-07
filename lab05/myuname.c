#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/utsname.h>


int main(int argc, char *argv[])
{
  struct utsname buf;
  int i;
  char *sysname;
  char *nodename;
  char *release;
  char *version;
  char *hwtype;
  if((i=uname(&buf))==-1){
    perror("uname");
    exit(1);}
   
  sysname = buf.sysname;
  nodename = buf.nodename;
  release = buf.release;
  version = buf.version;
  hwtype = buf.machine;
  
  printf("%s, %s, %s, %s, %s\n", sysname, nodename, release, version, hwtype);
}
