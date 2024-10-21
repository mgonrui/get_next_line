#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *ft_strjoin(char *s1, char *s2)
{
    char *res;
    int i;
    int j;
    
    i = 0;
    j = 0;
    res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!res)
        return (NULL);
    while (s1[i])
        res[j++] = s1[i++];
    i = 0;
    while (s2[i])
        res[j++] = s2[i];
    res[j] = 0;
    return (res);
}

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
    if (ft_strchr(buf, '\n') != NULL)
    {
        printf("%s\n", ft_strchr(buf, '\n'));
    }
    return buf;
}

char *get_next_line(int fd)
{
    char *buf;

    if (fd < 0)
        return NULL;
    
    buf = read_file(fd);
    return buf;
}