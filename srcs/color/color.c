/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:29:43 by khorike           #+#    #+#             */
/*   Updated: 2023/09/07 16:24:48 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

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

	r = (int)(color.red * 255);
	g = (int)(color.green * 255);
	b = (int)(color.blue * 255);
	return (rgb2hex(r, g, b));
}

// red, green, blue の値を0.0~1.0に丸める
t_color	color_normalize(t_color color)
{
	if (color.red < 0.0)
		color.red = 0.0;
	else if (color.red > 1.0)
		color.red = 1.0;
	if (color.green < 0.0)
		color.green = 0.0;
	else if (color.green > 1.0)
		color.green = 1.0;
	if (color.blue < 0.0)
		color.blue = 0.0;
	else if (color.blue > 1.0)
		color.blue = 1.0;
	return (color);
}

// 各成分から構造体の値を返す
t_color	color_init(double red, double green, double blue)
{
	t_color	result;

	result.red = red;
	result.green = green;
	result.blue = blue;
	return (result);
}

// "r,g,b" の形式の文字列をパースして color の指すアドレスに格納して, ステータスを返す(0: 成功. -1: 失敗)
int	get_color_from_rgbstr(t_color *color, char *rgbstr)
{
	char	*token;
	double	values[3];
	int		i;

	i = 0;
	token = ft_strtok(rgbstr, ",");
	while (token != NULL && i < 3)
	{
		values[i] = ft_atoi(token);
		token = ft_strtok(NULL, ",");
		i++;
	}
	if (i != 3)
	{
		exit(1);  // or return -1; if you don't want to terminate the program
		// printf("input str: %s\n", rgbstr);
		// return (put_and_return_err("failed parse string to color"));
	}
	color->red = values[0];
	color->green = values[1];
	color->blue = values[2];
	return (0);
}
