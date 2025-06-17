/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:40:45 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/18 18:58:29 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	convert_itoa(char *ptr, int *count, int num)
{
	while (num > 0)
	{
		ptr[--(*count)] = num % 10 + '0';
		num = num / 10;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	buf[42];
	int		i;
	int		flag;

	ft_memset(buf, 0, sizeof(buf));
	i = 40;
	flag = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		flag = 1;
	}
	if (n == 0)
	{
		buf[--i] = '0';
		return (ft_strdup(&buf[i]));
	}
	buf[--i] = '\0';
	convert_itoa(buf, &i, n);
	if (flag == 1)
		buf[--i] = '-';
	return (ft_strdup(&buf[i]));
}
