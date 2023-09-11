/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:39 by khorike           #+#    #+#             */
/*   Updated: 2023/09/11 17:47:59 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "mini_rt.h"

t_color	calculate_light_effect(t_world *world,
	t_ray ray, t_intersection intersection, t_object *object)
{
	t_list			*current_light;
	t_color			accumulated_color;
	t_shader_params	*shader_params;
	t_color			current_light_effect;

	current_light = world->lights;
	accumulated_color = color_init(0, 0, 0);
	shader_params = object->sha;
	shader_params->view_dir = vector_negate(ray.dir);
	shader_params->light_intensity = \
		((t_light *)current_light->content)->intensity;
	shader_params->light_dir = vector_normalize(vector_sub(((t_light *)
					current_light->content)->position, intersection.point));
	shader_params->normal = intersection.normal;
	current_light_effect = calculate_diffuse_and_specular(*shader_params);
	if (has_shadow(world, *(t_light *)current_light->content, intersection))
		current_light_effect = color_init(0, 0, 0);
	accumulated_color = color_add(accumulated_color, current_light_effect);
	return (accumulated_color);
}

// current_light: 現在処理している光源を指すリストのポインタです。
// accumulated_color: これまでの光源からの寄与を累積した色です。
// shader_params: オブジェクトのシェーダーのパラメータへのポインタ。
// current_light_effect: 現在の光源からの色の寄与を格納する変数です。