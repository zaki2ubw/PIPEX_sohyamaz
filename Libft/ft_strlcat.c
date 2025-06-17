/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:42:52 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 20:39:26 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	count;

	if (!dest || !src)
		return (0);
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	count = 0;
	while ((count++ != size) && (*dest != '\0'))
		dest ++;
	if (*dest != '\0')
		dlen = size;
	if (size == 0)
		return (slen);
	if (size <= dlen + 1)
		return (dlen + slen);
	count = size - dlen - 1;
	if (count <= 0)
		return (dlen + slen);
	while (*src != '\0' && count-- > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (dlen + slen);
}
