/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:07:04 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/17 14:51:16 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*dest;
	size_t	dlen;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start ++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end --;
	dlen = end - start;
	dest = (char *)malloc(sizeof(char) * (dlen + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1 + start, dlen);
	dest[dlen] = '\0';
	return (dest);
}
