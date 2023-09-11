/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:45:10 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/10 17:28:32 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	ft_error(char *error_mes)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_mes, 2);
	exit(1);
	return (1);
}