/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:48:24 by khorike           #+#    #+#             */
/*   Updated: 2023/09/12 14:52:33 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

// 光の強度、法線ベクトル、光源への単位ベクトルを元に、拡散反射の色を計算
t_color	calc_diffuse(t_shader_params params)
{
	t_color	result;
	double	dot_product;

	dot_product = vector_dot(params.normal, params.light_dir);
	if (dot_product < 0)
		return (color_init(0, 0, 0));
	result = color_mult_scalar(params.kdif, dot_product);
	ft_print_color(&result);
	// result = color_mult(result, );
	// ft_print_color(&result);
	return (result);
}

// I diffuse = I light × k d​ ×(N⋅L)
// I diffuse  は拡散反射の強度。
// I light  は光源の強度。
// k d  は拡散反射係数。
// N は物体の法線ベクトル。
// L は光源への単位ベクトル。
// N ⋅ Lはこれら2つのベクトルの内積。

// light_intensity: 光の強度や色。例えば、白色の光の強度や、青色の光の強度など。
// normal: 物体の表面上の点の法線ベクトル。これは光がどの方向に反射するかを知るために重要。
// light_dir: 光の方向。このベクトルは、物体上の点から光源に向かって伸びるベクトルです。
// kdif: 拡散反射係数。物体の色やどれだけ光を反射するかを表す係数。
