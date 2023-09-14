/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_cylinder.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:01:36 by khorike           #+#    #+#             */
/*   Updated: 2023/09/14 15:20:51 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

static t_qe	solve_quadratic_equation(t_ray ray, t_object *object)
{
	t_vector	dir_vec;
	t_vector	oc;
	t_qe		qe;

	dir_vec = ray.direction;
	oc = vector_sub(ray.start, *object->pos);
	qe.a = vector_dot(dir_vec, dir_vec) - \
			pow(vector_dot(dir_vec, *object->dir), 2);
	qe.b = 2 * (vector_dot(dir_vec, oc) - \
			vector_dot(dir_vec, *object->dir) * \
				vector_dot(oc, *object->dir));
	qe.c = vector_dot(oc, oc) - \
			pow(vector_dot(oc, *object->dir), 2) - \
			pow(object->diameter / 2, 2);
	qe.d = pow(qe.b, 2) - 4 * qe.a * qe.c;
	qe.t1 = (-qe.b - sqrt(qe.d)) / (2 * qe.a);
	qe.t2 = (-qe.b + sqrt(qe.d)) / (2 * qe.a);
	return (qe);
}

static t_shader_params	*calculate_intersection(double t, t_ray ray,
							t_object *object, t_world *world)
{
	t_shader_params	*ret;
	double			hit_point;
	t_vector		intersection_to_center;
	t_vector		projected;

	hit_point = vector_dot(ray.direction, *object->dir) * t + \
		vector_dot(vector_sub(ray.start, *object->pos), *object->dir);
	ret = NULL;
	if (t >= EPSILON && hit_point > EPSILON && hit_point <= object->height)
	{
		ret = shader_init(vector_add(ray.start,
					vector_mult(ray.direction, t)),
				*object, *world, vector_length(vector_mult(ray.direction, t)));
		intersection_to_center = vector_sub(ret->position, *object->pos);
		projected = vector_mult(*object->dir,
				vector_dot(intersection_to_center, *object->dir));
		ret->normal = vector_normalize(
				vector_sub(intersection_to_center, projected));
	}
	return (ret);
}

static t_shader_params	*select_closest_intersection(t_shader_params *ret1,
							t_shader_params *ret2, double t1, double t2)
{
	if (ret1 && ret2)
	{
		if (t1 < t2)
		{
			free(ret2);
			return (ret1);
		}
		else
		{
			free(ret1);
			return (ret2);
		}
	}
	if (ret1)
		return (ret1);
	if (ret2)
		return (ret2);
	return (NULL);
}

t_shader_params	*find_intersection_cylinder(t_world *world,
					t_object *object, t_ray ray)
{
	t_shader_params	*ret1;
	t_shader_params	*ret2;
	t_qe			qe;

	ret1 = NULL;
	ret2 = NULL;
	qe = solve_quadratic_equation(ray, object);
	if (fabs(qe.d) < EPSILON)
		return (NULL);
	ret1 = calculate_intersection(qe.t1, ray, object, world);
	ret2 = calculate_intersection(qe.t2, ray, object, world);
	return (select_closest_intersection(ret1, ret2, qe.t1, qe.t2));
}

// 円柱の中心線上の点を正確に特定することを目指しています。
// 具体的には、交点から円柱の中心線までのベクトルを取得し、
// そのベクトルから円柱の方向ベクトルの成分を除去します。

// intersection_to_center: 
// 交点から円柱の底面の中心へのベクトルを計算します。

// projected:
// 上記のベクトル上で、円柱の方向ベクトルの成分を求めます。
// これは、交点から円柱の中心軸上の点へのベクトルの計算に使用されます。
// 最後のステップで、intersection_to_centerからprojectedを引くことで、
// 円柱の側面の正確な法線ベクトルを得られます。