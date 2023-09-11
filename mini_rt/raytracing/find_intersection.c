/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:21:14 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 19:10:27 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int find_intersection(t_world *world, t_object *object, t_vector screen_vec)
{
	// t_intersection *intersection;

	// intersection = ft_calloc(sizeof(t_intersection), 1);
	// if (!intersection)
	// 	ft_error("Memory allocation error!\n")
	if (object->type == SPHERE)
		return (find_intersection_sphere(world, object, screen_vec));
	else if (object->type == PLANE)
		return (find_intersection_plane(world, object, screen_vec));
	// else if (object->type == CYLINDER)
	// 	return (find_intersection_cylinder(world, object, screen_vec));
}