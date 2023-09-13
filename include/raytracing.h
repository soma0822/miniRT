/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:12:02 by soma              #+#    #+#             */
/*   Updated: 2023/09/13 13:49:34 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "mini_rt.h"

t_shader_params *find_intersection(t_world *world, t_object *object, t_ray ray);
t_shader_params *find_intersection_sphere(t_world *world, t_object *object, t_ray ray);
t_shader_params *find_intersection_plane(t_world *world, t_object *object, t_ray ray);
t_shader_params *find_intersection_cylinder(t_world *world, t_object *object, t_ray ray);
t_shader_params *shader_init(t_vector position, t_object obj, t_world world, double distance);

#endif