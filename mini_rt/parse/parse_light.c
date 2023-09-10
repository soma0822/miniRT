/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:39:33 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 21:42:04 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	parse_light(char **split, t_world *world)
{
	t_light	*light;

	if (ft_split_length(split) != 4)
		ft_error("Light error!\n");
	light = ft_calloc(sizeof(t_light), 1);
	if (light == NULL)
		ft_error("Malloc failed!\n");
	light->pos = parse_vector(split[1]);
	light->ratio = ft_atof(split[2]);
	light->color = parse_color(split[3]);
	world->light = light;
	return (0);
}