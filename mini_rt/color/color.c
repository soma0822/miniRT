/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:22:35 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/14 14:14:52 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	rgb2hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

// t_color構造体をuint32_t型に変換する
uint32_t	color2hex(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color.r * 255);
	g = (int)(color.g * 255);
	b = (int)(color.b * 255);
	return (rgb2hex(r, g, b));
}

// r, g, b の値を0.0~1.0に丸める
t_color	color_normalize(t_color color)
{
	if (color.r < 0.0)
		color.r = 0.0;
	else if (color.r > 1.0)
		color.r = 1.0;
	if (color.g < 0.0)
		color.g = 0.0;
	else if (color.g > 1.0)
		color.g = 1.0;
	if (color.b < 0.0)
		color.b = 0.0;
	else if (color.b > 1.0)
		color.b = 1.0;
	return (color);
}

// 各成分から構造体の値を返す
t_color	color_init(double r, double g, double b)
{
	t_color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	return (result);
}
