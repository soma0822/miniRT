/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:22:05 by soma              #+#    #+#             */
/*   Updated: 2023/09/14 15:50:34 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	parse_cylinder(char **split, t_world *world)
{
	t_object	*cylinder;

	if (ft_split_length(split) != 6)
		return (1);
	cylinder = ft_calloc(sizeof(t_object), 1);
	if (cylinder == NULL)
		ft_error("Memory allocation error!\n");
	cylinder->type = CYLINDER;
	cylinder->pos = parse_vector(split[1]);
	cylinder->dir = parse_vector(split[2]);
	if (vector_length(*cylinder->dir) != 1)
		ft_error("Cylinder direction error!\n");
	cylinder->diameter = ft_atof(split[3]);
	cylinder->height = ft_atof(split[4]);
	cylinder->color = parse_color(split[5]);
	ft_lstadd_back(&world->objects, cylinder);
	return (0);
}
