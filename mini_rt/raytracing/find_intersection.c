/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:21:14 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:26:39 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_intersection find_intersection(t_world *world, t_vector screen_vec)
{
	t_intersection *intersection;

	intersection = ft_calloc(sizeof(t_intersection), 1);
	if (!intersection)
		ft_error("Memory allocation error!\n")
	if ()
}