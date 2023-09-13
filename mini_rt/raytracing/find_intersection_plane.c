/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_plane.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:05:07 by soma              #+#    #+#             */
/*   Updated: 2023/09/13 13:48:18 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params *find_intersection_plane(t_world *world, t_object *object, t_ray ray)
{
	t_vector dir_vec;
	dir_vec = ray.direction;
	if (vector_dot(dir_vec, *object->dir) == 0)
		return (0);
	double t = vector_dot(vector_sub(*object->pos, ray.start), *object->dir) / vector_dot(dir_vec, *object->dir);
	t_vector position = vector_add(ray.start, vector_mult(dir_vec, t));
	if (t > 0)
		return (shader_init(position, *object, *world, vector_length(vector_mult(dir_vec, t))));
	else
		return (NULL);
}