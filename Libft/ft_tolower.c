/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:08:27 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/22 19:09:58 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c = c + 32;
	}
	return (c);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char	str[] = "42tokyo";
//	char	str2[] = "42TOKYO";
//	char	str3[] = "42tOkyO";
//	int	i;
//
//	i = 0;
//	printf("before:%s\n", str);
//	while (str[i++] != '\0')
//		str[i] = ft_tolower(str[i]);
//	printf("After:%s\n", str);
//	i = 0;
//	printf("before:%s\n", str2);
//	while (str2[i++] != '\0')
//		str2[i] = ft_tolower(str2[i]);
//	printf("After:%s\n", str2);
//	i = 0;
//	printf("before:%s\n", str3);
//	while (str3[i++] != '\0')
//		str3[i] = ft_tolower(str3[i]);
//	printf("After:%s\n", str3);
//}
