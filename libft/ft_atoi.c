/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:28:35 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/23 21:48:36 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_atoi_helper(long long num, const char *str, size_t i, size_t flag)
{
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (num != 0 && num < LONG_MIN / 10)
		{
			if (flag == 0)
				return (LONG_MAX);
			if (flag == 1)
				return (LONG_MIN);
		}
		if (num != 0 && num == LONG_MIN / 10)
		{
			if (flag == 0 && str[i] >= '7')
				return (LONG_MAX);
			if (flag == 1 && str[i] >= '8')
				return (LONG_MIN);
		}
		num *= 10;
		num -= str[i] - '0';
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	size_t		flag;
	long long	num;

	if (str == NULL)
		return (0);
	i = 0;
	flag = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag++;
		i++;
	}
	num = ft_atoi_helper(num, str, i, flag);
	if (flag == 0 && num != LONG_MAX && num != LONG_MIN)
		return (-num);
	return (num);
}
/*
int	main(void)
{
	printf("%d\n", atoi("9223372036854775808"));
	printf("%d\n", ft_atoi("9223372036854775808"));
}*/