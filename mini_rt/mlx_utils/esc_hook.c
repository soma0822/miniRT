/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:46:35 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 16:53:33 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	esc_hook(int keycode, void *param)
{
	t_world	*world;

	world = (t_world *)param;
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(world->mlx_ptr, world->win_ptr);
		exit(0);
	}
	return (0);
}