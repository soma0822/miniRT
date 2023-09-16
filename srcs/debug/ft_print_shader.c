/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_shader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:53:12 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/14 19:57:37 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_shader(t_shader_params *param)
{
	printf("shader--------------\n");
	if (param == NULL)
		return ;
	if (param->type == SPHERE)
		printf("SPHERE\n");
	if (param->type == PLANE)
		printf("PLANE\n");
	if (param->type == CYLINDER)
		printf("CYLINDER\n");
	printf("position:");
	ft_print_vector(&param->position);
	printf("normal:");
	ft_print_vector(&param->normal);
	printf("light_pos_vec:");
	ft_print_vector(&param->light_pos_vec);
	printf("light_dir:");
	ft_print_vector(&param->light_dir);
}
