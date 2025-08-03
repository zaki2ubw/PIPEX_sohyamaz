/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:28:03 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/23 19:41:44 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	if (!s)
		return ;
	count = 0;
	while (s[count] != '\0')
	{
		ft_putchar_fd(s[count], fd);
		count ++;
	}
	ft_putchar_fd('\n', fd);
	return ;
}
