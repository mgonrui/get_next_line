#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *read_file(int fd)
{
    char *buf;
    int bytes_read;
    char *retvalue;
    buf = calloc(  BUFFER_SIZE + 1, sizeof(buf));
    if (buf == NULL)
        return NULL;
    bytes_read = read(fd, buf, BUFFER_SIZE);
    if (bytes_read <= 0)
        return (free(buf), NULL);
    ft_strjoin(retvalue, buf);
    if (ft_strchr(buf, '\n') != NULL)
    {

    }
    return retvalue;
}

char *get_next_line(int fd)
{
    char *line;

    if (fd < 0)
        return NULL;
    
    line = read_file(fd);
    return line;
}