/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:53:48 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/24 13:17:57 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int x)
{
	return ((ft_isalpha(x) == 1) || (ft_isdigit(x) == 1));
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
//		printf("%c is alnum? : %d\n", c, ft_isalnum(c));
//		c ++;
//	}
//	c = -42;
//	printf("%c is alnum? : %d\n", c, ft_isalnum(c));
//	c = INT_MAX;
//	printf("%c is alnum? : %d\n", c, ft_isalnum(c));
//	c = INT_MIN;
//	printf("%c is alnum? : %d\n", c, ft_isalnum(c));
//}
