/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:42:20 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 21:45:38 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	parse_plane(char **split, t_world *world)
{
	t_object	*plane;

	if (ft_split_length(split) != 4)
		ft_error("Plane format error!\n");
	plane = ft_calloc(sizeof(t_object), 1);
	if (plane == NULL)
		ft_error("Memory allocation error!\n");
	plane->type = PLANE;
	plane->pos = parse_vector(split[1]);
	plane->dir = parse_vector(split[2]);
	plane->color = parse_color(split[3]);
	ft_lstadd_back(&world->objects, plane);
	return (0);
}