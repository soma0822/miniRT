/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:21:14 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/12 16:29:10 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params	*find_intersection(t_world *world,
	t_object *object, t_vector screen_vec)
{
	if (object->type == SPHERE)
		return (find_intersection_sphere(world, object, screen_vec));
	else if (object->type == PLANE)
		return (find_intersection_plane(world, object, screen_vec));
	else if (object->type == CYLINDER)
		return (find_intersection_cylinder(world, object, screen_vec));
	return (0);
}
