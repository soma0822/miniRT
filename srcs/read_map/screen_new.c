/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:09:26 by soma              #+#    #+#             */
/*   Updated: 2023/09/15 12:32:12 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_screen	screen_new(t_camera *camera, t_world *world)
{
	t_screen	screen;

	world->camera->aspect_ratio = world->screen_width / world->screen_height;
	screen.center = vector_mult(vector_normalize(*camera->dir),
			world->screen_width / 2 / tan((camera->fov / 2) / 180 * M_PI));
	screen.x.x = screen.center.z
		/ sqrt(screen.center.z * screen.center.z
			+ screen.center.x * screen.center.x);
	screen.x.y = 0;
	screen.x.z = -screen.center.x
		/ sqrt(screen.center.z * screen.center.z
			+ screen.center.x * screen.center.x);
	screen.y = vector_normalize(vector_cross(screen.x,
				vector_mult(screen.center, -1)));
	if (camera->dir->x == 0 && camera->dir->y != 0 && camera->dir->z == 0)
	{
		screen.x = vector_init(1, 0, 0);
		screen.y = vector_init(0, 0, 1);
	}
	return (screen);
}
