/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:22:35 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/12 12:57:17 by khorike          ###   ########.fr       */
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

// "r,g,b" の形式の文字列をパースして color の指すアドレスに格納して, ステータスを返す(0: 成功. -1: 失敗)
// int	get_color_from_rgbstr(t_color *color, char *rgbstr)
// {
// 	char	*token;
// 	double	values[3];
// 	int		i;

// 	i = 0;
// 	token = ft_strtok(rgbstr, ",");
// 	while (token != NULL && i < 3)
// 	{
// 		values[i] = ft_atoi(token);
// 		token = ft_strtok(NULL, ",");
// 		i++;
// 	}
// 	if (i != 3)
// 	{
// 		exit(1);  // or return -1; if you don't want to terminate the program
// 		// printf("input str: %s\n", rgbstr);
// 		// return (put_and_return_err("failed parse string to color"));
// 	}
// 	color->r = values[0];
// 	color->g = values[1];
// 	color->b = values[2];
// 	return (0);
// }
