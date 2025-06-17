/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:34:24 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 20:28:28 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	len;

	if (!s)
		return (NULL);
	len = 0;
	len = ft_strlen(s);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_memmove(dest, s, len);
	dest[len] = '\0';
	return (dest);
}
