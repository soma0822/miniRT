/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:40:49 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/12 18:25:03 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define SHININESS 30
# define EPSILON 0.00001

# include <stdio.h>
# include <stdbool.h>
# include <stdbool.h>

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_vector
{
	double			x;
	double			y;
	double			z;
}	t_vector;

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
	void				*mlx_ptr;
	void				*win_ptr;
	int					screen_width;
	int					screen_height;
	t_img				img;
	struct s_ambient	*ambient;
	struct s_camera		*camera;
	struct s_light		*light;
	struct s_object		*objects;
	struct	s_vector	dir_vec;
}	t_world;

typedef struct s_ambient
{
	double			ratio;
	struct s_color	*color;
}	t_ambient;

typedef struct s_camera
{
	struct s_vector		*pos;
	struct s_vector		*dir;
	double				fov;
}	t_camera;

typedef struct s_light
{
	struct s_vector		*pos;
	double				ratio;
	struct s_color		*color;
}	t_light;

typedef struct s_object
{
	int						type;
	struct s_vector			*pos;
	struct s_vector			*dir;
	double					diameter;
	double					height;
	struct s_color			*color;
	struct s_object			*next;
	struct s_shader_params	*sha;
}	t_object;

// // 交点を表す構造体
// typedef struct	s_intersection {
// 	// 交点が存在するか
// 	bool		has_intersection;
// 	// 交点までの距離
// 	double		distance;
// 	// 交点の位置
// 	t_vector		position;
// 	// 交点における法線ベクトル
// 	t_vector		normal;
// }				t_intersection;

// レイ(光線)を表す構造体
typedef struct	s_ray {
	// レイの始点
	t_vector		start;
	// レイの方向ベクトル
	t_vector		direction;
}				t_ray;

typedef struct s_shader_params
{
	// 交点までの距離
	double		distance;
		// 交点の位置
	t_vector	position;
	t_vector	normal;
	t_vector	light_pos_vec;
	t_vector	light_dir;
	t_color		kspc;
	t_color		kdif;
	double		shininess;
}	t_shader_params;

#endif