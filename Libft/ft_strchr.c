/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:16:44 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 20:40:20 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*temp;
	unsigned char	check;

	if (!str)
		return (NULL);
	temp = (unsigned char *) str;
	check = (unsigned char) c;
	if (check == '\0')
	{
		while (*temp++ != '\0')
			str ++;
		return ((char *) str);
	}
	while (*temp != '\0')
	{
		if (*temp == check)
			return ((char *) str);
		temp ++;
		str ++;
	}
	return (NULL);
}
