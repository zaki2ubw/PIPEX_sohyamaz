/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:20:00 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/24 12:57:39 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	if (a > 31 && a < 127)
	{
		return (1);
	}
	return (0);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	unsigned int	c;
//
//	c = 0;
//	while (c < 128)
//	{
//		printf("%c is print? : %d\n", c, ft_isprint(c));
//		c ++;
//	}
//	c = -42;
//	printf("%c is print? : %d\n", c, ft_isprint(c));
//	c = INT_MAX;
//	printf("%c is print? : %d\n", c, ft_isprint(c));
//	c = INT_MIN;
//	printf("%c is print? : %d\n", c, ft_isprint(c));
//}
