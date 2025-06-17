/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:43:12 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/24 13:17:22 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
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
//		printf("%c is digit? : %d\n", c, ft_isdigit(c));
//		c ++;
//	}
//	c = -42;
//	printf("%c is digit? : %d\n", c, ft_isdigit(c));
//	c = INT_MAX;
//	printf("%c is digit? : %d\n", c, ft_isdigit(c));
//	c = INT_MIN;
//	printf("%c is digit? : %d\n", c, ft_isdigit(c));
//}
