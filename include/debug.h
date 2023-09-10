/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:17:00 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:20:28 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "include.h"
# include "mini_rt.h"

void	ft_print_ambient(t_ambient *ambient);
void	ft_print_camera(t_camera *camera);
void	ft_print_color(t_color *color);
void	ft_print_light(t_light *light);
void	ft_print_object(t_object *object);
void	ft_print_vector(t_vector *vector);
void	ft_print_world(t_world *world);

#endif