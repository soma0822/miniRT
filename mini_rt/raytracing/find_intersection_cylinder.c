/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_cylinder.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:22:42 by soma              #+#    #+#             */
/*   Updated: 2023/09/12 11:23:29 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	find_intersection_cylinder(t_world *world, t_object *object, t_vector screen_vec)
{
	t_vector dir_vec;
	t_vector oc;
	double a;
	double b;
	double c;
	double d;
	double t;

	dir_vec = vector_normalize(vector_sub(screen_vec, *world->camera->pos));
	oc = vector_sub(*world->camera->pos, *object->pos);
	a = vector_dot(dir_vec, dir_vec) - pow(vector_dot(dir_vec, *object->dir), 2);
	b = 2 * (vector_dot(dir_vec, oc) - vector_dot(dir_vec, *object->dir) * vector_dot(oc, *object->dir));
	c = vector_dot(oc, oc) - pow(vector_dot(oc, *object->dir), 2) - pow(object->diameter / 2, 2);
	d = pow(b, 2) - 4 * a * c;
	if (d < 0)
		return (0);
	t = (-b - sqrt(d)) / (2 * a);
	if (t > 0)
		return (1);
	else
		return (0);
}