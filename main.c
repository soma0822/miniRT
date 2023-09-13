/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/09/13 14:54:53 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mini_rt.h"
#include "include.h"
#include "material.h"
#include "matrix.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	*dst;

	dst = img->data + (y * img->line_size / 4 + x);
	*(unsigned int *)dst = color;
}

int raytracing(t_world *world)
{
	world->camera->aspect_ratio = world->screen_width / world->screen_height;
	t_screen screen;
	screen = screen_new(world->camera, world);
    for (double y = 0; y < world->screen_height; y++)
    {
        for (double x = 0; x < world->screen_width; x++)
        {
            // スクリーン座標からワールド座標への変換
            t_vector screen_vec;
			screen_vec = vector_add(vector_mult(screen.x,(2 * x / world->screen_width - 1.0)), vector_mult(screen.y, (2 * y / world->screen_height - 1.0)));
			screen_vec = vector_add(screen_vec, screen.center);
            // screen_vec = vector_init((2 * x / world->screen_width - 1.0), 2 * y / world->screen_height - 1.0, 0);
            // 方向ベクトル
            world->dir_vec = vector_normalize(vector_sub(screen_vec, *world->camera->pos));
            t_ray ray;
            ray.direction = world->dir_vec;
            ray.start = *world->camera->pos;
            // 交点の検出
            t_shader_params *params = find_intersection(world, world->objects, ray);
			if (params == NULL)
            {
                my_mlx_pixel_put(&world->img, x, y, rgb2hex(0,0,0));
            }
            else
            {
				t_color tmp;
				tmp = calculate_light_effect(world, *params);
                my_mlx_pixel_put(&world->img, x, y, color2hex(tmp));
            }
        }
    }
    return (0);
}

int	main(int ac, char **av)
{
	t_world *world;

	if (ac != 2)
		ft_error("Argument error!\n");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 3, ".rt", 3))
		ft_error("File extension error!\n");
	world = read_map(av[1]);
	world->mlx_ptr = mlx_init();
	world->screen_width = 800;
	world->screen_height = 600;
	world->win_ptr = mlx_new_window(world->mlx_ptr, world->screen_width, world->screen_height, "RayTracing with miniRT");
	world->img.img_ptr = mlx_new_image(world->mlx_ptr, world->screen_width, world->screen_height);
	world->img.data = (int *)mlx_get_data_addr(world->img.img_ptr, &world->img.bpp, &world->img.line_size, &world->img.endian);

	raytracing(world);
	// ft_print_world(world);

	mlx_put_image_to_window(world->mlx_ptr, world->win_ptr, world->img.img_ptr, 0, 0);
	mlx_hook(world->win_ptr, 17, 0, close_window, &world);
	mlx_hook(world->win_ptr, 2, 0, esc_hook, &world);
	mlx_loop(world->mlx_ptr);

	return (0);
}