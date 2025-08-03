/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:06:47 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/24 13:03:23 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (INT_MIN);
	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
		return (*str1 - *str2);
	while ((*str1 != '\0' || *str2 != '\0') && n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1 ++;
		str2 ++;
		n --;
	}
	return (0);
}
