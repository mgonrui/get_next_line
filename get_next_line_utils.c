/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgr <mgr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:04:15 by mgr               #+#    #+#             */
/*   Updated: 2024/10/21 17:24:32 by mgr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_size_until_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
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
