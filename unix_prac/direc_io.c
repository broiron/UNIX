#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
int main (int argc, char *argv[])
{
  const char *path;
  DIR *dp;

  mkdir(argv[1], 0644);
  mkdir(argv[2], 0644);
  
  dp = opendir(argv[1]);
  if((readdir(dp))==NULL){
    perror("readdir");
    exit(1);
  }
  closedir(dp);

  exit(0);
}






  
