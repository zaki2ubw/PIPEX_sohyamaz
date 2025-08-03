/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:52:31 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 17:19:10 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*left;
	const unsigned char	*right;

	left = (const unsigned char *) s1;
	right = (const unsigned char *) s2;
	while (n != 0)
	{
		if (*left != *right)
		{
			return (*left - *right);
		}
		left ++;
		right ++;
		n --;
	}
	return (0);
}
