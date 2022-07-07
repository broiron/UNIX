#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int sum=0;
  int pwd;
  for (int i=1; i<argc; i++){
    pwd = atoi(argv[i]);
    sum = sum+pwd;
    printf("%d ", i);
  }
  printf("\n");
  printf("sum=%d\n", sum);

  exit(0);
}
