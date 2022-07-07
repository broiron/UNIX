#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  time_t now_time;
  struct tm *local, *string_t;
  char *fstring_t;
  char buffer[100];
  
  time(&now_time);

  local = localtime(&now_time);
  string_t = gmtime(&now_time);
  fstring_t = asctime(local);

  printf("calendar time\t%ld\n", now_time);
  printf("string time\t%s\n", string_t);
  // printf("local time\t%d %d %d %d %d %d %d %d %d\n");
  strftime(buffer, 100, "%G %B %d %p %I %M %S", local);
  

  return (0);
}
