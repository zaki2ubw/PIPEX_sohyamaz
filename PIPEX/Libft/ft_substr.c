/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:52:13 by sohyamaz          #+#    #+#             */
/*   Updated: 2025/06/08 11:48:39 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			slen;

	if (s == NULL)
	{
		return (NULL);
	}
	slen = ft_strlen(s);
	if (start > slen)
	{
		return (ft_strdup(""));
	}
	else if (len > slen - start)
	{
		len = slen - start;
	}
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
