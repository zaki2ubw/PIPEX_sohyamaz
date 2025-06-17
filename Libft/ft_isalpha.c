/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:19:29 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/24 13:16:06 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
//		printf("%c is alpha? : %d\n", c, ft_isalpha(c));
//		c ++;
//	}
//	c = -42;
//	printf("%c is alpha? : %d\n", c, ft_isalpha(c));
//	c = INT_MAX;
//	printf("%c is alpha? : %d\n", c, ft_isalpha(c));
//	c = INT_MIN;
//	printf("%c is alpha? : %d\n", c, ft_isalpha(c));
//}
