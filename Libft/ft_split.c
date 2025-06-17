/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:55:45 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/17 21:37:34 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *str, char tgt)
{
	size_t	count;
	int		flag;
	int		i;

	count = 0;
	flag = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != tgt && flag == 0)
		{
			flag = 1;
			count ++;
		}
		else if (str[i] == tgt)
		{
			flag = 0;
		}
		i ++;
	}
	return (count);
}

void	*ft_cleanup(char **txt, size_t wc)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < wc)
	{
		free(txt[cnt]);
		cnt ++;
	}
	free(txt);
	return (NULL);
}

void	ft_getstart(const char *array, size_t *cpoint, size_t *spoint, char ck)
{
	while (array[*cpoint] == ck)
	{
		(*cpoint)++;
	}
	*spoint = *cpoint;
	while (array[*cpoint] != ck && array[*cpoint] != '\0')
	{
		(*cpoint)++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**outside;
	size_t	ocount;
	size_t	ret;
	size_t	start;
	size_t	current;

	ocount = ft_wordcount(s, c);
	outside = (char **)malloc(sizeof(char *) * (ocount + 1));
	if (outside == NULL || !s)
		return (NULL);
	current = 0;
	ret = 0;
	while (ret < ocount)
	{
		ft_getstart(s, &current, &start, c);
		outside[ret] = ft_substr(s, start, current - start);
		if (outside[ret] == NULL)
			return (ft_cleanup(outside, ret));
		ret ++;
	}
	outside[ret] = NULL;
	return (outside);
}
