/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:54:29 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:23:21 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

static double	ft_atof_decimal(char *nbr, double decimal)
{
	double	i;

	i = 1;
	while (*nbr >= '0' && *nbr <= '9')
	{
		i *= 0.1;
		decimal += (*nbr - '0') * i;
		nbr++;
	}
	return (decimal);
}

double	ft_atof(char *nbr)
{
	double	flag;
	double integer = 0;
	double decimal = 0;

	flag = 1;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			flag = -1;
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		integer = integer * 10 + *nbr++ - '0';
	}
	if (*nbr == '.')
		nbr++;
	decimal = ft_atof_decimal(nbr, decimal);
	return (flag * (integer + decimal));
}