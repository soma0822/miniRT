/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:12:02 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:12:46 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_light(t_light *light)
{
	printf("light\n");
	ft_print_vector(light->pos);
	printf("  ratio: %f\n", light->ratio);
	ft_print_color(light->color);
}