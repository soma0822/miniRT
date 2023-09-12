/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:41:41 by khorike           #+#    #+#             */
/*   Updated: 2023/09/12 15:57:40 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"
# include "vector.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "read_map.h"
# include "utils.h"
# include "parse.h"
# include "debug.h"
# include "mini_rt.h"

t_shader_params	material_init(t_color kdif, t_color kspe, double shininess);
t_shader_params	calculate_nomal_and_light_dir(t_vector light_position,
					t_vector position, t_vector sphere_vec);
t_color			calc_diffuse(t_shader_params params);
t_color			calc_specular(t_shader_params params);
t_color			calculate_diffuse_and_specular(t_shader_params params);
// t_color			calculate_light_effect(t_world *world,
// 					t_ray ray, t_intersection intersection, t_object *object);
#endif

// t_color light_intensity;  // 光の強度
// t_vector view_dir;        // 視線の方向
// t_vector normal;          // 衝突点の法線ベクトル
// t_vector light_dir;       // 光の方向
// t_color kspec;            // 鏡面反射係数
// t_color kdif;             // 拡散反射係数
// double shininess;         // 光沢度