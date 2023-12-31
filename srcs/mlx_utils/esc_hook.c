/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esc_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:46:35 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/14 22:56:18 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	esc_hook(int keycode, void *param)
{
	t_world	*world;

	world = (t_world *)param;
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}
