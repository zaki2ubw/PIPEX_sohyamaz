/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:52:45 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/05 21:38:53 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	c;

	c = 0;
	if (!*s)
	{
		return (0);
	}
	while (s[c] != '\0')
	{
		c ++;
	}
	return (c);
}

//#include <stdio.h>
//int	main(int argc,char *argv[])
//{
//	char *s;
//
//	s = "teststr";
//	printf("%s:%zu\n", s ,ft_strlen(s));
//	printf("%s:%zu\n", argv[argc - 1] ,ft_strlen(argv[argc - 1]));
//	return (0);
//}
