/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:12:02 by soma              #+#    #+#             */
/*   Updated: 2023/09/12 11:32:01 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_H
# define RAYTRACING_H

# include "mini_rt.h"

int find_intersection(t_world *world, t_object *object, t_vector screen_vec);
int find_intersection_sphere(t_world *world, t_object *object, t_vector screen_vec);
int find_intersection_plane(t_world *world, t_object *object, t_vector screen_vec);
int	find_intersection_cylinder(t_world *world, t_object *object, t_vector screen_vec);

#endif