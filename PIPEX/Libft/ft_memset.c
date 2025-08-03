/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:16:26 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 19:24:13 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!s)
	{
		return (s);
	}
	p = (unsigned char *) s;
	while (n > 0)
	{
		*p = (unsigned char) c;
		n --;
		p ++;
	}
	return (s);
}
