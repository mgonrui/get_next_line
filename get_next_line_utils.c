#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*p_str;
	char	c_is_char;

	p_str = (char *)str;
	c_is_char = (char)c;
	while (*p_str)
	{
		if (c_is_char == *p_str)
		{
			return (p_str);
		}
		p_str++;
	}
	if (c == 0 || c == 1024)
		return (p_str);
	else
		return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	int				i;
	int				limit;

	ptr = malloc(size * count);
	if (ptr == NULL)
		return (0);
	i = 0;
	limit = count * size;
	while (i < limit)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

void	ft_cpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*conc_str;

	conc_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(conc_str))
		return (NULL);
	ft_cpy(conc_str, s1);
	ft_cpy(&conc_str[ft_strlen(conc_str)], s2);
	return (conc_str);
}
