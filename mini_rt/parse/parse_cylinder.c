/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:22:05 by soma              #+#    #+#             */
/*   Updated: 2023/09/13 22:38:07 by sinagaki         ###   ########.fr       */
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
	cylinder->diameter = ft_atof(split[3]);
	cylinder->height = ft_atof(split[4]);
	cylinder->color = parse_color(split[5]);
	ft_lstadd_back(&world->objects, cylinder);
	return (0);
}
