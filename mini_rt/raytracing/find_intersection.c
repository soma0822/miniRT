/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:21:14 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/12 17:15:28 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params *find_intersection(t_world *world, t_object *object, t_vector screen_vec)
{
	t_object *tmp;
	t_shader_params *material;
	t_shader_params *ret;

	tmp = object;
	ret = NULL;
	while (tmp != NULL)
	{
		if (object->type == SPHERE)
			material = find_intersection_sphere(world, object, screen_vec);
		else if (object->type == PLANE)
			material = find_intersection_plane(world, object, screen_vec);
		else if (object->type == CYLINDER)
			material = find_intersection_cylinder(world, object, screen_vec);
		if (ret == NULL || ret->distance > material->distance)
			ret = material;
		tmp = tmp->next;
	}
	return (ret);
}
