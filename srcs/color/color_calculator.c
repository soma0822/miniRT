/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:23:34 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 15:11:05 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "mini_rt.h"

// t_color同士の足し算
t_color	color_add(t_color a, t_color b)
{
	t_color	result;

	result.r = a.r + b.r;
	result.g = a.g + b.g;
	result.b = a.b + b.b;
	return (color_normalize(result));
}

// t_color同士の各要素同士の掛け算
t_color	color_mult(t_color a, t_color b)
{
	t_color	result;

	result.r = a.r * b.r;
	result.g = a.g * b.g;
	result.b = a.b * b.b;
	return (result);
}

// t_fcolor同士の定数倍
t_color	color_mult_scalar(t_color a, double scalar)
{
	t_color	result;

	result.r = a.r * scalar;
	result.g = a.g * scalar;
	result.b = a.b * scalar;
	return (color_normalize(result));
}

// カラーの計算が終わった後に、その値が期待される範囲内にあることを保証
t_color	color_clamp(t_color c)
{
	if (c.r < 0)
		c.r = 0;
	else if (c.r > 1.0)
		c.r = 1.0;
	if (c.g < 0)
		c.g = 0;
	else if (c.g > 1.0)
		c.g = 1.0;
	if (c.b < 0)
		c.b = 0;
	else if (c.b > 1.0)
		c.b = 1.0;
	return (c);
}
