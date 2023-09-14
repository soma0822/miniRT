/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:19:32 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/14 16:17:24 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params	*shader_init(t_vector position, t_object obj,
					t_world world, double distance)
{
	t_shader_params	*material;

	material = ft_calloc(sizeof(t_shader_params), 1);
	if (!material)
		ft_error("Memory allocation error!\n");
	material->type = obj.type;
	material->distance = distance;
	material->position = position;
	material->normal = vector_normalize(vector_sub(position, *obj.pos));
	if (world.light)
	{
		material->light_pos_vec = vector_sub(*world.light->pos, position);
		material->light_dir = \
		vector_normalize(material->light_pos_vec);
	}
	material->kdif = *obj.color;
	if (obj.type == SPHERE)
		material->kspc = color_init(0.9, 0.9, 0.9);
	else
		material->kspc = color_init(0.3, 0.3, 0.3);
	material->shininess = SHININESS;
	return (material);
}
