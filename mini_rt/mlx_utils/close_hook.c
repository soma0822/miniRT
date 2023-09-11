/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:40:17 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 16:53:39 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	close_window(void *param)
{
	t_world	*world;

	world = (t_world *)param;
	mlx_destroy_window(world->mlx_ptr, world->win_ptr);
	exit(0);
	return (0);
}