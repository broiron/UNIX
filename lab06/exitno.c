#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i;
  i = atoi(argv[1]);
  printf("exit=%d\n", i);
  exit(i);
}
