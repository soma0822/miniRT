/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_sphere.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:43:11 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 19:04:11 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int find_intersection_sphere(t_world *world, t_object *object, t_vector screen_vec)
{
	// t_intersection *intersection;

	// intersection = ft_calloc(sizeof(t_intersection), 1);
	// if (!intersection)
	// 	ft_error("Memory allocation error!\n");
	t_vector dir_vec;
	dir_vec = vector_normalize(vector_sub(screen_vec, *world->camera->pos));
	t_vector camera2sphere_vec = vector_sub(*world->camera->pos, *object->pos);
	double a = vector_length(dir_vec) * vector_length(dir_vec);
	double b = 2 * vector_dot(camera2sphere_vec, dir_vec);
	double c = vector_dot(camera2sphere_vec, camera2sphere_vec) - (object->diameter / 2) * (object->diameter / 2);
	double d = b * b - 4 * a * c;
	if (d >= 0)
		return (1);
	else
		return (0);
}