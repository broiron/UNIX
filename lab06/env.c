#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(void)
{
  int index = 0;  
  while(1){
    printf("%s\n", environ[index]);
    index++;
    if(environ[index] == NULL) break;
  }    
  exit(0);
}
