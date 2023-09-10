/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:04:33 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:20:58 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_world(t_world *world)
{
	ft_print_ambient(world->ambient);
	ft_print_camera(world->camera);
	ft_print_light(world->light);
	ft_print_object(world->objects);
}