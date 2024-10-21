#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) 
{
  int fd;
  char *line;
  // int count = 1;
  
  fd = open("example.txt", O_RDONLY);
  while(1)
  {
    line = get_next_line(fd);
    if (line == NULL)
      break;
    free(line);
  }
  close(fd);
  return 0;
}