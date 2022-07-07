#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  time_t pt;
  char *string_time;
  
  time(&pt);
  printf("%ld\n", pt);

  string_time = ctime(&pt);
  printf("%s", string_time);
  
}
