/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:55:53 by khorike           #+#    #+#             */
/*   Updated: 2023/09/07 16:22:12 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

// t_color同士の足し算
t_color	color_add(t_color a, t_color b)
{
	t_color	result;

	result.red = a.red + b.red;
	result.green = a.green + b.green;
	result.blue = a.blue + b.blue;
	return (color_normalize(result));
}

// t_color同士の各要素同士の掛け算
t_color	color_mult(t_color a, t_color b)
{
	t_color	result;

	result.red = a.red * b.red;
	result.green = a.green * b.green;
	result.blue = a.blue * b.blue;
	return (result);
}

// t_fcolor同士の定数倍
t_color	color_mult_scalar(t_color a, double scalar)
{
	t_color	result;

	result.red = a.red * scalar;
	result.green = a.green * scalar;
	result.blue = a.blue * scalar;
	return (color_normalize(result));
}

// カラーの計算が終わった後に、その値が期待される範囲内にあることを保証
t_color	color_clamp(t_color c)
{
	if (c.red < 0)
		c.red = 0;
	else if (c.red > 1.0)
		c.red = 1.0;
	if (c.green < 0)
		c.green = 0;
	else if (c.green > 1.0)
		c.green = 1.0;
	if (c.blue < 0)
		c.blue = 0;
	else if (c.blue > 1.0)
		c.blue = 1.0;
	return (c);
}
