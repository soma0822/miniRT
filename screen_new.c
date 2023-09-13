/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:09:26 by soma              #+#    #+#             */
/*   Updated: 2023/09/13 15:06:50 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "mini_rt.h"
 #include "include.h"

// t_screen   screen_new(t_camera *camera, t_world *world)
// {
// 	t_screen    screen;

// 	screen.x.x = camera->dir->z / sqrt(pow(camera->dir->z, 2) + pow(camera->dir->x, 2));
// 	screen.x.y = 0;
// 	screen.x.z = -camera->dir->x / sqrt(pow(camera->dir->z, 2) + pow(camera->dir->x, 2));
// 	screen.y = vector_cross(*camera->dir, screen.x);
// 	screen.center = vector_mult(*camera->pos, tan(camera->fov / 2));
// 	return (screen);
// }


t_screen screen_new(t_camera *camera, t_world *world)
{
    t_screen screen;

    // カメラの方向ベクトル
    t_vector forward = *camera->dir;

    // スクリーン座標系のx軸（右方向）
    screen.x = vector_normalize(vector_cross(forward, (t_vector){0, 1, 0}));

    // スクリーン座標系のy軸（上方向）
    screen.y = vector_normalize(vector_cross(screen.x, forward));

    // スクリーン中心の位置（ワールド座標系）
    screen.center = vector_add(*camera->pos, vector_mult(forward, camera->near_plane_distance));

    return screen;
}
