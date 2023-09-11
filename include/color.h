/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:13:44 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 14:29:14 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "include.h"
# include "mini_rt.h"

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