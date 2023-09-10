/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:16:16 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:21:39 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_vector	*parse_vector(char *str)
{
	char		**split;
	t_vector	*vector;

	split = ft_split(str, ',');
	if (split == NULL)
		ft_error("Memory allocation error!\n");
	vector = ft_calloc(sizeof(t_vector), 1);
	if (vector == NULL)
		ft_error("Memory allocation error!\n");
	if (ft_split_length(split) != 3)
		ft_error("Vector format error!\n");
	vector->x = ft_atof(split[0]);
	vector->y = ft_atof(split[1]);
	vector->z = ft_atof(split[2]);
	ft_free_twod_array(split);
	return (vector);
}
