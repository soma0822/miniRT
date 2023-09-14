/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_sphere.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:43:11 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/14 15:10:13 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

// 2次方程式を計算する関数
static t_qe	calculate_quadratic(t_ray ray, t_object *object)
{
	t_vector	dir_vec;
	t_vector	camera2sphere_vec;
	t_qe		qe;

	dir_vec = ray.direction;
	camera2sphere_vec = vector_sub(ray.start, *object->pos);
	qe.a = vector_length(dir_vec) * vector_length(dir_vec);
	qe.b = 2 * vector_dot(camera2sphere_vec, dir_vec);
	qe.c = vector_dot(camera2sphere_vec, camera2sphere_vec) - \
			(object->diameter / 2) * (object->diameter / 2);
	qe.d = qe.b * qe.b - 4 * qe.a * qe.c;
	return (qe);
}

t_shader_params	*find_intersection_sphere(t_world *world,
			t_object *object, t_ray ray)
{
	t_vector	dir_vec;
	t_vector	position;
	t_qe		qe;

	dir_vec = ray.direction;
	qe = calculate_quadratic(ray, object);
	qe.t1 = (-qe.b - sqrt(qe.d)) / (2 * qe.a);
	qe.t2 = (-qe.b + sqrt(qe.d)) / (2 * qe.a);
	if (qe.t1 >= 0)
	{
		return (shader_init(vector_add(ray.start, vector_mult(dir_vec, qe.t1)),
				*object, *world, vector_length(vector_mult(dir_vec, qe.t1))));
	}
	position = vector_add(ray.start, vector_mult(dir_vec, qe.t2));
	if (qe.t2 >= 0)
	{
		return (shader_init(position, *object, *world,
				vector_length(vector_mult(dir_vec, qe.t2))));
	}
	return (NULL);
}
