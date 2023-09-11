/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:26:29 by khorike           #+#    #+#             */
/*   Updated: 2023/09/07 16:24:11 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../libft/libft.h"

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

t_color		color_add(t_color a, t_color b);
t_color		color_sub(t_color a, t_color b);
t_color		color_mult(t_color a, t_color b);
t_color		color_clamp(t_color c);

int			rgb2hex(int r, int g, int b);
uint32_t	color2hex(t_color color);
t_color		color_normalize(t_color color);
t_color		color_init(double red, double green, double blue);
int			get_color_from_rgbstr(t_color *color, char *rgbstr);

#endif
