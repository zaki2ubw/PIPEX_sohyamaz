/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:21:16 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 20:20:26 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	dlen;
	char	*dest;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dlen = s1len + s2len + 1;
	dest = (char *)malloc(sizeof(char) * dlen);
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2 != '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
