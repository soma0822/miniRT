/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_plane.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:05:07 by soma              #+#    #+#             */
/*   Updated: 2023/09/13 22:06:04 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params *find_intersection_plane(t_world *world, t_object *object, t_ray ray)
{
	t_vector dir_vec;
	double	dot;
	t_shader_params *ret;

	dir_vec = ray.direction;
	dot = vector_dot(dir_vec, *object->dir);
	if (dot == 0)
		return (0);
	double t = vector_dot(vector_sub(*object->pos, ray.start), *object->dir) / dot;
	t_vector position = vector_add(ray.start, vector_mult(dir_vec, t));
	if (t > 0)
	{
		ret = shader_init(position, *object, *world, vector_length(vector_mult(dir_vec, t)));
		ret->normal = dot > 0 ? *object->dir : vector_mult(*object->dir, -1);
		return (ret);
	}
	else
		return (NULL);
}