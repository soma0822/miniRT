/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:21:14 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/14 16:32:14 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params	*find_intersection(t_world *world, t_object *object, t_ray ray)
{
	t_object		*tmp;
	t_shader_params	*material;
	t_shader_params	*ret;

	tmp = object;
	ret = NULL;
	while (tmp != NULL)
	{
		if (tmp->type == SPHERE)
			material = find_intersection_sphere(world, tmp, ray);
		else if (tmp->type == PLANE)
			material = find_intersection_plane(world, tmp, ray);
		else if (tmp->type == CYLINDER)
			material = find_intersection_cylinder(world, tmp, ray);
		if ((material != NULL) && (ret == NULL || \
				ret->distance > material->distance))
		{
			free(ret);
			ret = material;
		}
		tmp = tmp->next;
	}
	return (ret);
}
