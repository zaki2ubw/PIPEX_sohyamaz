/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:24:18 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 20:12:01 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *tgt, size_t n)
{
	size_t	slen;
	size_t	tlen;

	if (!src || !tgt)
		return (NULL);
	slen = ft_strlen(src);
	tlen = ft_strlen(tgt);
	if (tlen == 0)
		return ((char *)src);
	if (tlen > slen)
		return (NULL);
	while (slen-- >= tlen && n-- >= tlen)
	{
		if (ft_strncmp(src, tgt, tlen) == 0)
			return ((char *)src);
		src ++;
	}
	return (NULL);
}
