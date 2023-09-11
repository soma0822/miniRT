/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_plane.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:05:07 by soma              #+#    #+#             */
/*   Updated: 2023/09/11 19:10:12 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int find_intersection_plane(t_world *world, t_object *object, t_vector screen_vec)
{
	// t_intersection *intersection;

	// intersection = ft_calloc(sizeof(t_intersection), 1);
	// if (!intersection)
	// 	ft_error("Memory allocation error!\n");
	t_vector dir_vec;
	dir_vec = vector_normalize(vector_sub(screen_vec, *world->camera->pos));
	if (vector_dot(dir_vec, *object->dir) == 0)
		return (0);
	double t = vector_dot(vector_sub(*object->pos, *world->camera->pos), *object->dir) / vector_dot(dir_vec, *object->dir);
	if (t > 0)
		return (1);
	else
		return (0);
}