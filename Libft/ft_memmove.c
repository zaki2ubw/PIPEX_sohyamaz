/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:33:09 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/20 19:13:37 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest || !src)
		return (dest);
	if (dest == src)
		return (dest);
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	if (d < s)
	{
		while (n != 0)
		{
			*d ++ = *s ++;
			n --;
		}
	}
	if (s < d)
	{
		d = d + n - 1;
		s = s + n - 1;
		while (n-- != 0)
			*d -- = *s --;
	}
	return (dest);
}
