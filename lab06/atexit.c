#include <stdio.h>
#include <stdlib.h>

int i;

void fun1(void){
  printf("exit=%d\n", i);
}

int main(int argc, char *argv[])
{
  i = atoi(argv[1]);
  atexit(fun1);

  exit(i);
}


