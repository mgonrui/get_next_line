/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgr <mgr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:04:15 by mgr               #+#    #+#             */
/*   Updated: 2024/10/21 18:20:23 by mgr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *ft_calloc(size_t num, size_t size)
{
    char *p_calloc;
	size_t i;
	i = 0;
    p_calloc = malloc(num * size);
    if (p_calloc == NULL)
        return NULL;
	while (i < (num * size))
		p_calloc[i++] = 0;
    return  (void *)p_calloc;
}
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
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

char *ft_strdup(const char *s1)
{
    char *dest;
    size_t i;
    dest = (char *) malloc(ft_strlen(s1) + 1);
    if (!dest)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    char *str;
    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    str = ft_calloc(len + 1, sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    return (str);
}





