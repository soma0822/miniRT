/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:23:33 by khorike           #+#    #+#             */
/*   Updated: 2023/12/06 15:21:46 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"
#include "material.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	*dst;

	dst = img->data + (y * img->line_size / 4 + x);
	*(unsigned int *)dst = color;
}

static t_vector	calculate_ray_direction(t_world *world,
			t_screen screen, double x, double y)
{
	double		sw;
	double		sh;
	t_vector	xx;
	t_vector	yy;

	sw = x - (world->screen_width - 1) / 2;
	sh = (world->screen_height - 1) / 2 - y;
	xx = vector_mult(screen.x, sw);
	yy = vector_mult(screen.y, sh);
	return (vector_normalize(vector_add(screen.center, vector_add(xx, yy))));
}

t_ray	calculate_ray(t_world *world, t_screen screen, double x, double y)
{
	t_vector	ray_direction;
	t_ray		ray;

	ray_direction = calculate_ray_direction(world, screen, x, y);
	world->dir_vec = ray.direction;
	ray.direction = ray_direction;
	ray.start = *world->camera->pos;
	return (ray);
}

static int	raytracing(t_world *world)
{
	t_screen		screen;
	static double	y = 0;
	double			x;
	t_ray			ray;
	t_shader_params	*params;

	screen = get_screen_start_position(*world);
	while (y < world->screen_height)
	{
		x = -1;
		while (++x < world->screen_width)
		{
			ray = calculate_ray(world, screen, x, y);
			params = NULL;
			params = find_intersection(world, world->objects, ray);
			if (params == NULL)
				my_mlx_pixel_put(&world->img, x, y, rgb2hex(0, 0, 0));
			else
				my_mlx_pixel_put(&world->img, x, y,
					color2hex(calculate_light_effect(world, *params)));
			free(params);
		}
		y++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_world	*world;

	if (ac != 2)
		ft_error("Argument error!\n");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 3, ".rt", 3))
		ft_error("File extension error!\n");
	world = read_map(av[1]);
	world->mlx_ptr = mlx_init();
	world->screen_width = 800;
	world->screen_height = 600;
	world->win_ptr = mlx_new_window(world->mlx_ptr, world->screen_width,
			world->screen_height, "RayTracing with miniRT");
	world->img.img_ptr = mlx_new_image(world->mlx_ptr, world->screen_width,
			world->screen_height);
	world->img.data = (int *)mlx_get_data_addr(world->img.img_ptr,
			&world->img.bpp, &world->img.line_size, &world->img.endian);
	raytracing(world);
	mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
		world->img.img_ptr, 0, 0);
	mlx_hook(world->win_ptr, 17, 0, close_window, &world);
	mlx_hook(world->win_ptr, 2, 0, esc_hook, &world);
	mlx_loop(world->mlx_ptr);
	return (0);
}
