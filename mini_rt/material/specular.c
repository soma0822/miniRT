/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:42:38 by khorike           #+#    #+#             */
/*   Updated: 2023/09/12 16:50:23 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_color	calc_specular(t_shader_params params, t_world world)
{
	t_vector	reflect_dir;
	double		spec;
	t_color		result;
	double		dot_product;

	dot_product = vector_dot(params.light_dir, params.normal);
	reflect_dir = vector_sub(vector_mult(params.normal, 2 * dot_product),
			params.light_dir);
	reflect_dir = vector_normalize(reflect_dir);
	spec = vector_dot(world.dir_vec, reflect_dir);
	if (spec < 0.0)
		spec = 0.0;
	spec = pow(spec, params.shininess);
	result = color_mult_scalar(params.kspc, spec);
	// result = color_mult(result, params.light_intensity);
	return (result);
}

// t_vector reflect_dir;    // 反射ベクトル
// double spec;             // 鏡面反射の強度
// t_color result;          // 結果の色

// 鏡面反射
// 光の方向と物体の表面の向きを使って、反射の方向を計算
// R = 2(N * L)N - L
// 反射光の方向を正規化:
// reflect_dir = vector_normalize(reflect_dir); この行で、反射光の方向を正規化

// ここでのspecは、反射ベクトルと視線ベクトルの間の角度を考慮した値です。
// params.shininessは物体の光沢度（ハイライトの鋭さ）を示す値です。