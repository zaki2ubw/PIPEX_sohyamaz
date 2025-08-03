/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:56:27 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 19:15:13 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;

	if (!s)
	{
		return (NULL);
	}
	temp = (unsigned char *) s;
	while (n != 0)
	{
		if (*temp == (unsigned char)c)
		{
			return (temp);
		}
		temp ++;
		n --;
	}
	return (NULL);
}
