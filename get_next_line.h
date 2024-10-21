#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line(int fd);
int	ft_size_until_c(char *str, char c);
char	*ft_strchr(const char *str, int c);
void *ft_calloc(size_t num, size_t size);
char	*ft_strjoin(char *s1, char *s2);


typedef struct node
{
    char *str;
    struct node *next;

} node;
#endif