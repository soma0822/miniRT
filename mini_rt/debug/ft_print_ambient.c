/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:09:30 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:11:00 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_ambient(t_ambient *ambient)
{
	printf("ambient\n");
	printf("  ratio: %f\n", ambient->ratio);
	ft_print_color(ambient->color);
}