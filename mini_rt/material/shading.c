/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:39 by khorike           #+#    #+#             */
/*   Updated: 2023/09/12 16:54:51 by khorike          ###   ########.fr       */
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

// bool		has_shadow(t_world *world, t_light light, t_intersection intersection)
// {
// 	// 交点から光源までのベクトルの計算
// 	t_vec3 intersection2light;
// 	intersection2light = vec3_sub(light.position, intersection.position);
// 	// 入射ベクトル
// 	t_vec3 l = vec3_normalize(intersection2light);
// 	// シャドウレイ
// 	// 始点は微小距離ずらすことで物体自身と交差が出ないようにする
// 	t_ray shadow_ray;
// 	shadow_ray.start = vec3_add(intersection.position, vec3_mult(l, EPSILON));
// 	shadow_ray.direction = l;
// 	// 交点から光源までの距離
// 	double light_dist = vec3_mag(intersection2light) - EPSILON;
// 	// シャドウベクトルが交点とぶつかる&&light_distより小さい ということは交点と光源との間に物体があるということ
// 	t_list *current_object = world->objects;
// 	while (current_object)
// 	{
// 		t_intersection inter = calc_intersection(shadow_ray, *(t_object*)current_object->content);
// 		if (inter.has_intersection && inter.distance >= 0 && inter.distance <= light_dist)
// 		{
// 			return (true);
// 		}
// 		current_object = current_object->next;
// 	}
// 	return (false);
// }

t_color	calculate_light_effect(t_world *world, t_shader_params params)
{
	t_color			ref_ambient;
	// t_shader_params	light_effect;
	t_color			ref_result;

	ref_result = calculate_diffuse_and_specular(params, *world);
	// if (has_shadow(world, *world->light, intersection))
	// 	current_light_effect = color_init(0, 0, 0);
	// accumulated_color = color_add(accumulated_color, current_light_effect);
	ref_ambient = color_mult(params.kdif, *world->ambient->color);
	ref_result = color_add(ref_ambient, ref_result);
	return (ref_result);
}

// current_light: 現在処理している光源を指すリストのポインタです。
// accumulated_color: これまでの光源からの寄与を累積した色です。
// shader_params: オブジェクトのシェーダーのパラメータへのポインタ。
// current_light_effect: 現在の光源からの色の寄与を格納する変数です。