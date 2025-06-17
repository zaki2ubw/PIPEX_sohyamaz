/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:12 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/13 21:31:27 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buf;

	if (size == 0 || nmemb == 0)
	{
		buf = (unsigned char *)malloc(1);
		if (buf == NULL)
		{
			return (NULL);
		}
		return (buf);
	}
	if (size != 0 && nmemb != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	buf = (unsigned char *)malloc(size * nmemb);
	if (buf == NULL)
	{
		return (NULL);
	}
	ft_bzero(buf, (size * nmemb));
	return (buf);
}
