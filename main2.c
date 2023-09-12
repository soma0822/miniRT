/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:44:36 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/12 14:52:15 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"
#include "material.h"
#include "mini_rt.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	*dst;

	dst = img->data + (y * img->line_size / 4 + x);
	*(unsigned int *)dst = color;
}

int raytracing(t_world *world)
{
    // 視点位置を表すベクトル
    t_vector camera_vec;
    camera_vec = vector_init(0, 0, -100);  // スクリーンの少し手前な感じ

    // 球の中心座標
    t_vector sphere_vec;
    sphere_vec = vector_init(0, 0, 5);  // スクリーンの少し奥な感じ
    double sphere_r = 1;  // 半径

    for (double y = 0; y < world->screen_height; y++)
    {
        for (double x = 0; x < world->screen_width; x++)
        {
            // スクリーン座標からワールド座標への変換
            t_vector screen_vec;
            screen_vec = vector_init(2 * x / world->screen_width - 1.0, 2 * y / world->screen_height - 1.0, 0);

            // 方向ベクトル
            t_vector dir_vec;
            dir_vec = vector_normalize(vector_sub(screen_vec, camera_vec));

            // 
            t_vector camera2sphere_vec = vector_sub(camera_vec, sphere_vec);

            // レイが球に当たったか計算する
            double a = vector_length(dir_vec) * vector_length(dir_vec);
            double b = 2 * vector_dot(camera2sphere_vec, dir_vec);
            double c = vector_dot(camera2sphere_vec, camera2sphere_vec) - sphere_r * sphere_r;
            // 判別式
            double d = b * b - 4 * a * c;
            if (d >= 0)
            {
                // t_color color;
                
                t_color tmp;
                t_shader_params material;
                t_vector position =  vector_add(camera_vec, vector_mult(dir_vec, (-b + sqrt(d)) / (2 * a)));
                t_vector light_position = vector_init(-30, 30, 20);
                material = calculate_nomal_and_light_dir(light_position,
	            position, sphere_vec);
                // material = material_init(color_init(0, 1.0, 0),color_init(0.3, 0.3, 0.3), SHININESS);
                tmp = calculate_diffuse_and_specular(material);
                // tmp = calculate_light_effect(world, ray, intersection, &object);
                my_mlx_pixel_put(&world->img, x, y, color2hex(tmp));
            }
            else
            {
                my_mlx_pixel_put(&world->img, x, y, rgb2hex(0, 0, 255));
            }
        }
    }
    return (0);
}


int	main(void)
{
	t_world world;

	world.mlx_ptr = mlx_init();
	world.screen_width = 800;
	world.screen_height = 600;
	world.win_ptr = mlx_new_window(world.mlx_ptr, world.screen_width, world.screen_height, "RayTracing with miniRT");
	world.img.img_ptr = mlx_new_image(world.mlx_ptr, world.screen_width, world.screen_height);
	world.img.data = (int *)mlx_get_data_addr(world.img.img_ptr, &world.img.bpp, &world.img.line_size, &world.img.endian);

	raytracing(&world);

	mlx_put_image_to_window(world.mlx_ptr, world.win_ptr, world.img.img_ptr, 0, 0);
	mlx_hook(world.win_ptr, 17, 0, close_window, &world);
	mlx_hook(world.win_ptr, 2, 0, esc_hook, &world);
	mlx_loop(world.mlx_ptr);

	return (0);
}
