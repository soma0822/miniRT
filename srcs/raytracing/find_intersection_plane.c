/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_plane.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:05:07 by soma              #+#    #+#             */
/*   Updated: 2023/09/14 14:35:14 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params	*find_intersection_plane(t_world *world,
					t_object *object, t_ray ray)
{
	t_vector		dir_vec;
	double			dot;
	t_shader_params	*ret;
	t_vector		position;
	double			t;

	dir_vec = ray.direction;
	dot = vector_dot(dir_vec, *object->dir);
	if (fabs(dot) < EPSILON)
		return (0);
	t = vector_dot(vector_sub(*object->pos, ray.start), *object->dir) / dot;
	position = vector_add(ray.start, vector_mult(dir_vec, t));
	if (t > 0)
	{
		ret = shader_init(position, *object, *world,
				vector_length(vector_mult(dir_vec, t)));
		if (fabs(dot) > EPSILON)
			ret->normal = *object->dir;
		else
			ret->normal = vector_mult(*object->dir, -1);
		return (ret);
	}
	else
		return (NULL);
}
