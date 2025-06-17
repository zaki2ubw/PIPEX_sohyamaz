/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:05 by sohyamaz          #+#    #+#             */
/*   Updated: 2024/11/22 21:37:41 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	chk_overflow(long n, const char *c, int f)
{
	if ((LONG_MAX / 10 < n)
		|| (LONG_MAX / 10 == n && *c - '0' > LONG_MAX % 10))
	{
		if (f == 1)
		{
			n = LONG_MIN;
			return (n);
		}
		else
		{
			n = LONG_MAX;
			return (n);
		}
	}
	return (n);
}

long	atoi_func(const char *text, int i)
{
	long	val;

	val = 0;
	while (*text >= '0' && *text <= '9')
	{
		val = (val * 10) + (*text - '0');
		val = chk_overflow(val, text, i);
		if (val == LONG_MAX || val == LONG_MIN)
			return (val);
		text ++;
	}
	return (val);
}

int	ft_atoi(const char *str)
{
	int		flag;
	long	v;

	v = 0;
	flag = 0;
	if (!*str)
		return (0);
	while ((*str > 8 && *str < 14) || (*str == 32))
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = 1;
		str ++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	v = atoi_func(str, flag);
	if (v == LONG_MAX || v == LONG_MIN)
		return ((int)v);
	if (flag == 1)
		v = -v;
	return ((int)v);
}

//#include <stdio.h>
//
//int	main(int argc, char **argv)
//{
//	char	*spaces = "\f\n\r\t\v 	";
//	char	*sign = "+-";
//	char	*string = "42tokyo";
//	char	*others = "tokyo42";
//	char	*skip = "	  +-";
//	char	*ret = "	  -42	35 - 46";
//	char	*imax = "2147483647";
//	char	*imin = "-2147483648";
//	char	*limh = "9223372036854775807";
//	char	*liml = "-9223372036854775808";
//	char	*over = "429223372036854775807";
//	char	*under = "-429223372036854775808";
//
//	printf("case1 spaces:%d\n", ft_atoi(spaces));
//	printf("case2 sign:%d\n", ft_atoi(sign));
//	printf("case3 string:%d\n", ft_atoi(string));
//	printf("case4 others:%d\n", ft_atoi(others));
//	printf("case5 skip:%d\n", ft_atoi(skip));
//	printf("case6 truereturn:%d\n", ft_atoi(ret));
//	printf("case7 INT_MAX:%d\n", ft_atoi(imax));
//	printf("case8 INT_MIN:%d\n", ft_atoi(imin));
//	printf("case9 maxofstrtol:%d\n", ft_atoi(limh));
//	printf("case10 minofstrtol:%d\n", ft_atoi(liml));
//	printf("case11 overflowinstrtol:%d\n", ft_atoi(over));
//	printf("case12 underflowinstrtol:%d\n", ft_atoi(under));
//	if (argc != 1)
//		printf("caseEX StringYouWant2Test:%d\n", ft_atoi(argv[argc - 1]));
//}
