/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_advanced.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:30:20 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/14 14:27:54 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// 内積.2つのベクトルの対応する成分を掛け合わせ、その結果を合計する操作
// 2つのベクトルの間の角度を求めるときや、
// ベクトルが特定の方向にどれだけ向いているか（投影）を計算
// スクリーンへの反射など
double	vector_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// 外積.3次元空間内の2つのベクトルを使用して、
// それら2つのベクトルに直交する新しいベクトルを生成する操作
// 3Dグラフィックスでの面の法線ベクトルの計算や、
// ベクトルが構築する平面上に垂直な方向を見つけるときなどに使用
t_vector	vector_cross(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

t_vector	vector_normalize(t_vector a)
{
	t_vector	result;
	double		magnitude;

	magnitude = vector_length(a);
	if (magnitude == 0.0)
	{
		return (a);
	}
	result.x = a.x / magnitude;
	result.y = a.y / magnitude;
	result.z = a.z / magnitude;
	return (result);
}
