/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:46:40 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:22:04 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "include.h"

int	parse_ambient(char **split, t_world *world);
int	parse_camera(char **split, t_world *world);
t_color	*parse_color(char *str);
int	parse_cylinder(char **split, t_world *world);
int	parse_error(char **split, t_world *world);
int	parse_light(char **split, t_world *world);
int	parse_plane(char **split, t_world *world);
int	parse_sphere(char **split, t_world *world);
t_vector	*parse_vector(char *str);


#endif