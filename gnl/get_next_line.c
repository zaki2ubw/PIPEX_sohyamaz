/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:14:53 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/12/30 15:16:46 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_char(int fd)
{
	static char		buf[BUFFER_SIZE];
	static char		*bufptr;
	static int		remain;
	unsigned char	asc;

	if (remain == 0)
	{
		remain = read(fd, buf, BUFFER_SIZE);
		if (remain == 0)
			return (EOF);
		if (remain < 0)
			return (INT_MIN);
		bufptr = buf;
	}
	asc = 0;
	if (remain > 0)
	{
		asc = (unsigned char) *bufptr;
		bufptr ++;
		remain --;
		return (asc);
	}
	else
		return (EOF);
}

char	*set_next_line(int asc, char *val)
{
	if (asc == EOF)
	{
		if (*val == '\0')
		{
			free (val);
			return (NULL);
		}
		return (val);
	}
	if (asc == INT_MIN)
	{
		if (val != NULL)
			free (val);
		return (NULL);
	}
	val = gnl_strjoin(val, asc);
	if (val == NULL)
		return (NULL);
	return (val);
}

char	*get_next_line(int fd)
{
	char	*val;
	int		asc;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	val = gnl_calloc(sizeof(char), 1);
	if (val == NULL)
		return (NULL);
	while (1)
	{
		asc = get_next_char(fd);
		val = set_next_line(asc, val);
		if (val == NULL)
			return (NULL);
		if (asc == '\n' || asc == EOF)
			break ;
	}
	return (val);
}
