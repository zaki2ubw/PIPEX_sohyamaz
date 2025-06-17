/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:13:58 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/12/22 18:14:12 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char c)
{
	size_t	dsize;
	char	*dest;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	dsize = gnl_strlen(s1) + 2;
	dest = (char *)malloc(sizeof(char) * dsize);
	if (dest == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = c;
	i++;
	dest[i] = '\0';
	free (s1);
	return (dest);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buf;

	if (size == 0 || nmemb == 0)
	{
		buf = (unsigned char *)malloc(0);
		if (buf == NULL)
		{
			return (NULL);
		}
		return (buf);
	}
	if (size != 0 && nmemb != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	buf = (unsigned char *)malloc(size * nmemb);
	if (buf == NULL)
	{
		return (NULL);
	}
	gnl_bzero(buf, (size * nmemb));
	return (buf);
}

void	gnl_bzero(void *s, size_t n)
{
	unsigned char	*p;

	if (!s)
		return ;
	p = (unsigned char *) s;
	while (n != 0)
	{
		*p = 0;
		n --;
		p++;
	}
	return ;
}

size_t	gnl_strlen(char *s)
{
	unsigned int	c;

	c = 0;
	if (!*s)
	{
		return (0);
	}
	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}
