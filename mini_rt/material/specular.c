/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:42:38 by khorike           #+#    #+#             */
/*   Updated: 2023/09/14 13:33:43 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_color	calc_specular(t_shader_params params, t_world world)
{
	t_vector	l;
	t_vector	v;
	t_vector	r;
	t_color		result;

	l = vector_normalize(vector_sub(*world.light->pos, params.position));
	v = vector_mult(world.dir_vec, -1);
	r = vector_sub(vector_mult(vector_mult(params.normal,
					vector_dot(params.normal, l)), 2), l);
	result = color_mult_scalar(params.kspc,
			pow(vector_dot(v, r), params.shininess));
	if (vector_dot(v, r) < EPSILON)
	{
		result = color_init(0, 0, 0);
	}
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