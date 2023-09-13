/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:50:19 by soma              #+#    #+#             */
/*   Updated: 2023/09/13 12:45:05 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	parse_ambient(char **split, t_world *world)
{
	t_ambient	*ambient;

	if (world->ambient != NULL)
		ft_error("Ambient light already exists!\n");
	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (ambient == NULL)
		ft_error("Memory allocation error!\n");
	if (ft_split_length(split) != 3)
		return (1);
	ambient->ratio = ft_atof(split[1]);
	if (ambient->ratio < 0 || ambient->ratio > 1)
		ft_error("Ambient ratio error!\n");
	ambient->color = parse_color(split[2]);
	world->ambient = ambient;
	return (0);
}
