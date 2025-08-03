/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:05:56 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/21 21:02:03 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
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
//		printf("%c is ascii? : %d\n", c, ft_isascii(c));
//		c ++;
//	}
//	c = -42;
//	printf("%c is ascii? : %d\n", c, ft_isascii(c));
//	c = INT_MAX;
//	printf("%c is ascii? : %d\n", c, ft_isascii(c));
//	c = INT_MIN;
//	printf("%c is ascii? : %d\n", c, ft_isascii(c));
//}
