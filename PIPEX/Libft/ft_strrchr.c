/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:36:13 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 20:25:24 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	*temp;
	unsigned char	*org;
	unsigned char	check;

	if (!str)
		return (NULL);
	org = (unsigned char *) str;
	str = str + ft_strlen(str);
	temp = (unsigned char *) str;
	check = (unsigned char) c;
	while (org != temp)
	{
		if (*temp == check)
		{
			return ((char *)str);
		}
		str --;
		temp --;
	}
	if (*str == check)
	{
		return ((char *)str);
	}
	return (NULL);
}
