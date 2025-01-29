#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 30
#endif // BUFFER_SIZE

char *get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
void	ft_cpy(char *dest, const char *src);
int	ft_strlen(char *str);

#endif // GET_NEXT_LINE_H_
