/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:40:49 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 14:41:24 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

#include <stdio.h> 

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef struct s_world
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		screen_width;
	int		screen_height;
	t_img	img;
	struct s_ambient	*ambient;
	struct s_camera		*camera;
	struct s_light		*light;
	struct s_object		*objects;
}	t_world;

typedef struct s_ambient
{
	double			ratio;
	struct s_color		*color;
}	t_ambient;

typedef struct s_camera
{
	struct s_vector		*pos;
	struct s_vector		*dir;
	double			fov;
}	t_camera;

typedef struct s_light
{
	struct s_vector		*pos;
	double			ratio;
	struct s_color		*color;
}	t_light;

typedef struct s_object
{
	int					type;
	struct s_vector		*pos;
	struct s_vector		*dir;
	double				diameter;
	double				height;
	struct s_color		*color;
	struct s_object		*next;
}	t_object;

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}	t_vector;

#endif