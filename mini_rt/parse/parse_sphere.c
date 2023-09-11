/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:44:28 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 21:48:01 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	parse_sphere(char **split, t_world *world)
{
	t_object	*sphere;

	if (ft_split_length(split) != 4)
		ft_error("Sphere error!\n");
	sphere = ft_calloc(sizeof(t_object), 1);
	if (!sphere)
		ft_error("Malloc failed!\n");
	sphere->type = SPHERE;
	sphere->pos = parse_vector(split[1]);
	sphere->diameter = ft_atof(split[2]);
	sphere->color = parse_color(split[3]);
	ft_lstadd_back(&world->objects,  sphere);
	return (0);
}