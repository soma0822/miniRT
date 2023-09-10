/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:10:09 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 21:21:21 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	parse_camera(char **split, t_world *world)
{
	t_camera	*camera;

	if (world->camera != NULL)
		ft_error("Multiple camera error!\n");
	if (ft_split_length(split) != 4)
		ft_error("Camera format error!\n");
	camera = (t_camera *)ft_calloc(sizeof(t_camera), 1);
	if (camera == NULL)
		ft_error("Memory allocation error!\n");
	camera->pos = parse_vector(split[1]);
	camera->dir = parse_vector(split[2]);
	camera->fov = ft_atof(split[3]);
	if (camera->fov < 0 || camera->fov > 180)
		ft_error("Camera fov error!\n");
	world->camera = camera;
	return (0);
}