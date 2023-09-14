/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:39 by khorike           #+#    #+#             */
/*   Updated: 2023/09/14 14:18:28 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "mini_rt.h"

t_color	calculate_diffuse_and_specular(t_shader_params params, t_world world)
{
	t_color	diffuse_color;
	t_color	specular_color;

	diffuse_color = calc_diffuse(params, world);
	specular_color = calc_specular(params, world);
	return (color_add(diffuse_color, specular_color));
}

bool	has_shadow(t_world world, t_shader_params intersection)
{
	t_ray			ray;
	t_vector		ins_to_light;
	t_vector		l;
	t_shader_params	*tmp;
	double			light_dist;

	ins_to_light = vector_sub(*world.light->pos, intersection.position);
	l = vector_normalize(ins_to_light);
	ray.start = vector_add(intersection.position, vector_mult(l, EPSILON));
	ray.direction = l;
	light_dist = vector_length(ins_to_light) - EPSILON;
	tmp = find_intersection(&world, world.objects, ray);
	if (tmp && tmp->distance > EPSILON && tmp->distance <= light_dist)
	{
		return (true);
	}
	return (false);
}

t_color	calculate_light_effect(t_world *world, t_shader_params params)
{
	t_color			ref_ambient;
	t_color			current_light_effect;
	t_color			ref_result;
	t_color			ref_result2;

	current_light_effect = calculate_diffuse_and_specular(params, *world);
	ref_result2 = color_init(0, 0, 0);
	if (has_shadow(*world, params))
	{
		current_light_effect = color_init(0, 0, 0);
	}
	ref_result2 = color_add(ref_result2, current_light_effect);
	ref_ambient = color_mult(params.kdif, *world->ambient->color);
	ref_result = color_add(ref_ambient, ref_result2);
	return (ref_result);
}

// current_light: 現在処理している光源を指すリストのポインタです。
// accumulated_color: これまでの光源からの寄与を累積した色です。
// shader_params: オブジェクトのシェーダーのパラメータへのポインタ。
// current_light_effect: 現在の光源からの色の寄与を格納する変数です。

// 交点から光源へのベクトル
// direction_to_light