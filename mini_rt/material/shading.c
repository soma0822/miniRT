/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:39 by khorike           #+#    #+#             */
/*   Updated: 2023/09/11 18:25:17 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "mini_rt.h"

static t_color	calculate_diffuse_and_specular(t_shader_params params)
{
	t_color	diffuse_color;
	t_color	specular_color;

	diffuse_color = calc_diffuse(params);
	specular_color = calc_specular(params);
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

t_color	calculate_light_effect(t_world *world,
	t_ray ray, t_intersection intersection, t_object *object)
{
	t_color			accumulated_color;
	t_shader_params	*shader_params;
	t_color			current_light_effect;

	accumulated_color = color_init(0, 0, 0);
	shader_params = object->sha;
	shader_params->view_dir = vector_negate(ray.direction);
	shader_params->light_intensity = world->light->ratio;
	shader_params->light_dir = vector_normalize(vector_sub(*world->light->pos, intersection.position));
	shader_params->normal = intersection.normal;
	current_light_effect = calculate_diffuse_and_specular(*shader_params);
	// if (has_shadow(world, *world->light, intersection))
	// 	current_light_effect = color_init(0, 0, 0);
	accumulated_color = color_add(accumulated_color, current_light_effect);
	return (accumulated_color);
}

// current_light: 現在処理している光源を指すリストのポインタです。
// accumulated_color: これまでの光源からの寄与を累積した色です。
// shader_params: オブジェクトのシェーダーのパラメータへのポインタ。
// current_light_effect: 現在の光源からの色の寄与を格納する変数です。