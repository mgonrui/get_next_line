#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    /* printf("%s", line); */
    return 0;
}
