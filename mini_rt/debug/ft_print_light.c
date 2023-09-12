/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:12:02 by soma              #+#    #+#             */
/*   Updated: 2023/09/11 19:26:45 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_light(t_light *light)
{
	printf("light\n");
	if (light == NULL)
	{
		printf("  (null)");
		return ;
	}
	ft_print_vector(light->pos);
	printf("  ratio: %f\n", light->ratio);
	ft_print_color(light->color);
}