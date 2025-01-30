#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char *read_chunks(int fd, char *buffer)
{
    int byteread;
    char *read_buffer;
    char *swap;

    byteread = 1;
    read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (read_buffer == NULL)
        return NULL;
    while(byteread > 0 && !ft_strchr(read_buffer, '\n'))
    {
        byteread = read(fd, read_buffer, BUFFER_SIZE);
        if (byteread == -1)
        {
            return (free(buffer), free(read_buffer), NULL);
        }
        read_buffer[byteread] = '\0';
        swap = ft_strjoin(buffer, read_buffer);
        free(buffer);
        buffer = swap;
    }
    return (free(read_buffer), buffer);
}

char *extract_line(char *buffer)
{
    char *line;
    int line_len;

    if (buffer[0] == '\0')
        return NULL;
    line_len = 0;
    while (buffer[line_len] != '\n' && buffer[line_len] != '\0')
        line_len++;
    line = ft_calloc(line_len + 2, sizeof(char));
    if (line == NULL)
        return NULL;
    line_len = 0;
    while (buffer[line_len] != '\n' && buffer[line_len] != '\0')
    {
        line[line_len] = buffer[line_len];
        line_len++;
    }
    if (buffer[line_len] == '\n')
        line[line_len] = '\n';
    return line;
}

char *leave_leftovers(char *buffer)
{
    char *leftovers;
    int i;
    int line_len;

    i = 0;
    line_len = 0;
    while (buffer[line_len] != '\n' && buffer[line_len] != '\0')
        line_len++;
    if (buffer[line_len] == '\0')
        return (free(buffer), NULL);
    line_len++;
    leftovers = ft_calloc(ft_strlen(buffer) - line_len + 1, sizeof(char));
    if (leftovers == NULL)
        return (free(buffer), NULL);
    while (buffer[line_len + i] != '\0')
    {
        leftovers[i] = buffer[line_len + i];
        i++;
    }
    return (free(buffer), leftovers);
}




char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    if (buffer == NULL)
        buffer = ft_calloc(1, 1);
    buffer = read_chunks(fd, buffer);
    if (buffer == NULL)
        return NULL;
    line = extract_line(buffer);
    buffer = leave_leftovers(buffer);
    return line;

}
