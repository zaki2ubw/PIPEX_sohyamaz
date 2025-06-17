/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:49:46 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/07 21:51:29 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (!dest || !src)
	{
		return (dest);
	}
	if (dest == src)
	{
		return (dest);
	}
	while (n != 0)
	{
		*d = *s;
		d ++;
		s ++;
		n --;
	}
	return (dest);
}
