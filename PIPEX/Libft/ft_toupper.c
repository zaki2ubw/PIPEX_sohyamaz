/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:02:02 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/22 19:09:19 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
	{
		c = c - 32;
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
//		str[i] = ft_toupper(str[i]);
//	printf("After:%s\n", str);
//	i = 0;
//	printf("before:%s\n", str2);
//	while (str2[i++] != '\0')
//		str2[i] = ft_toupper(str2[i]);
//	printf("After:%s\n", str2);
//	i = 0;
//	printf("before:%s\n", str3);
//	while (str3[i++] != '\0')
//		str3[i] = ft_tolower(str3[i]);
//	printf("After:%s\n", str3);
//}
