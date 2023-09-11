/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:42:38 by khorike           #+#    #+#             */
/*   Updated: 2023/09/11 15:51:48 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_color	calc_specular(t_color light_intensity, t_vector view_dir,
	t_vector normal, t_vector light_dir, t_color kspec, double shininess)
{
    t_vector reflect_dir;    // 反射ベクトル
    double spec;             // 鏡面反射の強度
    t_color result;          // 結果の色

    // 反射ベクトルを計算
    double dot_product = vector_dot(light_dir, normal);
    reflect_dir = vector_sub(vector_mult_scalar(normal, 2 * dot_product), light_dir);
    reflect_dir = vector_normalize(reflect_dir);

    // 視線ベクトルと反射ベクトルの内積の計算
    spec = vector_dot(view_dir, reflect_dir);
    if (spec < 0.0) spec = 0.0;

    // shininessは物体の鏡面反射の鋭さを示すパラメータです。
    // 高いshininess値は小さい、鋭いハイライトをもたらします。
    spec = pow(spec, shininess);

    result = color_mult_scalar(kspec, spec);
    result = color_mult(result, light_intensity);

    return result;
}
