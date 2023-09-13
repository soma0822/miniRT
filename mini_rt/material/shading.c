/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:39 by khorike           #+#    #+#             */
/*   Updated: 2023/09/13 13:22:14 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "mini_rt.h"

t_color	calculate_diffuse_and_specular(t_shader_params params, t_world world)
{
	t_color	diffuse_color;
	t_color	specular_color;

	diffuse_color = calc_diffuse(params);
	specular_color = calc_specular(params, world);
	return (color_add(diffuse_color, specular_color));
}

t_vector	vector_negate(t_vector a)
{
	t_vector	result;

	result.x = -a.x;
	result.y = -a.y;
	result.z = -a.z;
	return (result);
}

bool	has_shadow(t_world world, t_shader_params intersection)
{
	// t_vector	direction_to_light;
	double		light_dist;
	t_object	*current_object;

	intersection.position = vector_add(intersection.position,
			vector_mult(vector_normalize(intersection.light_dir), EPSILON));
	intersection.light_dir = vector_normalize(intersection.light_dir);
	light_dist = vector_length(intersection.light_pos_vec) - EPSILON;
	current_object = world.objects;
	// while (current_object)
	// {
	// 	// 当たり判定をやり、たい
	// 	if (inter.has_intersection && intersection.distance >= 0 && intersection.distance <= light_dist)
	// 	{
	// 		return (true);
	// 	}
	// 	current_object = current_object->next;
	// }
	return (false);
}

t_color	calculate_light_effect(t_world *world, t_shader_params params)
{
	t_color			ref_ambient;
	// t_shader_params	light_effect;
	// t_color			current_light_effect;
	t_color			ref_result;
	// t_color			ref_diff_spec;

	ref_result = calculate_diffuse_and_specular(params, *world);
	// if (has_shadow(*world, light_effect))
	// 	current_light_effect = color_init(0, 0, 0);
	// ref_diff_spec = color_add(ref_diff_spec, current_light_effect);
	ref_ambient = color_mult(params.kdif, *world->ambient->color);
	ref_result = color_add(ref_ambient, ref_result);
	// ref_result = color_add(ref_ambient, ref_diff_spec);
	return (ref_result);
}

// current_light: 現在処理している光源を指すリストのポインタです。
// accumulated_color: これまでの光源からの寄与を累積した色です。
// shader_params: オブジェクトのシェーダーのパラメータへのポインタ。
// current_light_effect: 現在の光源からの色の寄与を格納する変数です。

// 交点から光源へのベクトル
// direction_to_light