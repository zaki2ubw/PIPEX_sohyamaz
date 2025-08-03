/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:03:56 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 20:44:55 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	ret;

	if (!dest || !src)
		return (0);
	ret = ft_strlen(src);
	if (len == 0)
		return (ret);
	else if (len == 1)
	{
		*dest = '\0';
		return (ret);
	}
	while ((*src != '\0') && (len - 1 != 0))
	{
		*dest = *src;
		dest ++;
		src ++;
		len --;
	}
	*dest = '\0';
	return (ret);
}
