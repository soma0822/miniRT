/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:40:15 by khorike           #+#    #+#             */
/*   Updated: 2023/09/13 12:54:23 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"
#include "material.h"
#include "matrix.h"



t_matrix	perspective_projection_matrix(t_camera *camera)
{
	t_matrix	matrix;
	double		tan_half_fov = tan(camera->fov / 2.0);

    // 簡略化のために近クリップ面と遠クリップ面の設定は省略します
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            matrix.m[i][j] = 0;
        }
    }

    matrix.m[0][0] = 1.0 / (camera->aspect_ratio * tan_half_fov);
    matrix.m[1][1] = 1.0 / tan_half_fov;
    matrix.m[2][2] = -1; // 簡略化のために一定の値を使用
    matrix.m[3][2] = -1;
    matrix.m[2][3] = -2; // 簡略化のために一定の値を使用

    return matrix;
}

// ベクトルを行列で変換する関数
t_vector	transform_vector(t_matrix *matrix, t_vector v)
{
	t_vector	result;

	result.x = v.x * matrix->m[0][0] + v.y * matrix->m[0][1] + v.z * matrix->m[0][2] + matrix->m[0][3];
	result.y = v.x * matrix->m[1][0] + v.y * matrix->m[1][1] + v.z * matrix->m[1][2] + matrix->m[1][3];
	result.z = v.x * matrix->m[2][0] + v.y * matrix->m[2][1] + v.z * matrix->m[2][2] + matrix->m[2][3];
	// wは簡略化のため計算しない
	return (result);
}
