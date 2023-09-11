/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:21:04 by khorike           #+#    #+#             */
/*   Updated: 2023/09/07 16:42:34 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// int	setting_img(void *param)
// {
// 	t_game	*game;
// 	ssize_t	hei;
// 	ssize_t	wid;

// 	game = (t_game *)param;
// 	hei = -1;
// 	while (++hei < game->hei)
// 	{
// 		wid = 0;
// 		while (wid < game->wid)
// 		{
// 			if (game->str_line[hei * game->wid + wid] == '1')
// 				draw_wall(game, wid, hei);
// 			else if (game->str_line[hei * game->wid + wid] == 'C')
// 				draw_chest(game, wid, hei);
// 			else if (game->str_line[hei * game->wid + wid] == 'P')
// 				draw_player(game, wid, hei);
// 			else if (game->str_line[hei * game->wid + wid] == 'E')
// 				draw_rune(game, wid, hei);
// 			else
// 				draw_land(game, wid, hei);
// 			wid++;
// 		}
// 	}
// 	return (0);
// }

// int	handle_key_press(int key_code, t_game *game)
// {
// 	if (key_code == KEY_ESC)
// 	{
// 		game->esc = 1;
// 		exit_game(game);
// 	}
// 	else if (key_code == KEY_W || key_code == KEY_ARROW_UP)
// 		move_player_up(game);
// 	else if (key_code == KEY_A || key_code == KEY_ARROW_LEFT)
// 		move_player_left(game);
// 	else if (key_code == KEY_S || key_code == KEY_ARROW_DOWN)
// 		move_player_down(game);
// 	else if (key_code == KEY_D || key_code == KEY_ARROW_RIGHT)
// 		move_player_right(game);
// 	return (0);
// }

// void	initialize_images(t_game *game)
// {
// 	int		img_width;
// 	int		img_height;

// 	game->s_img.wall = mlx_xpm_file_to_image(game->mlx,
// 			"./images/wall.xpm", &img_width, &img_height);
// 	game->s_img.chest = mlx_xpm_file_to_image(game->mlx,
// 			"./images/chest.xpm", &img_width, &img_height);
// 	game->s_img.chara = mlx_xpm_file_to_image(game->mlx,
// 			"./images/chara.xpm", &img_width, &img_height);
// 	game->s_img.rune = mlx_xpm_file_to_image(game->mlx,
// 			"./images/cherry.xpm", &img_width, &img_height);
// 	game->s_img.land = mlx_xpm_file_to_image(game->mlx,
// 			"./images/land.xpm", &img_width, &img_height);
// 	game->hei = 0;
// 	game->wid = 0;
// 	game->player_x = 0;
// 	game->player_y = 0;
// 	game->counter = 0;
// 	game->esc = 0;
// 	game->kaigyou_count = 0;
// 	game->item_count = 0;
// 	game->total__item_count = 0;
// 	game->error = 0;
// 	game->now_item_iti = 0;
// 	game->str_line = NULL;
// }

// int	handle_window_close(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	free(game->str_line);
// 	mlx_destroy_window(game->mlx, game->win);
// 	exit(0);
// 	return (0);
// }

// int	main(int ac, char *av[])
// {
// 	t_game	game;
// 	char	*filename;
// 	void	*mlx;
// 	void	*win;

// 	mlx = mlx_init();
// 	game.mlx = mlx;
// 	filename = av[1];
// 	initialize_images(&game);
// 	if (ac != 2)
// 		put_error("Error\n", &game);
// 	if (!map_read(filename, &game) || (game.kaigyou_count != game.hei - 2))
// 		put_error("Error\n", &game);
// 	if (!check_read_map(&game) || !check_read_map_2(&game)
// 		|| !check_read_map_3(&game) || !can_reach_goal(&game)
// 		|| !can_reach_chara(&game))
// 		put_error("Error\n", &game);
// 	win = mlx_new_window(mlx, game.wid * 50, game.hei * 50, "my_mlx");
// 	mlx_hook(win, 17, 0, handle_window_close, &game);
// 	game.win = win;
// 	setting_img(&game);
// 	mlx_key_hook(game.win, handle_key_press, &game);
// 	mlx_loop_hook(mlx, setting_img, &game);
// 	mlx_loop(mlx);
// 	return (0);
// }

#include "mlx.h"
#include "../includes/color.h"
#include <stdio.h>

#include <stdint.h>

// int main(void)
// {
//     void *mlx;
//     void *win;
//     t_color color1 = color_init(0.5, 0.2, 0.8);
//     t_color color2 = color_init(0.2, 0.6, 0.1);
//     t_color added = color_add(color1, color2);

//     // Initialize the MLX context
//     mlx = mlx_init();

//     // Create a new window
//     win = mlx_new_window(mlx, 800, 600, "Color Test");

//     // Drawing a couple of rectangles with different colors to test
//     for (int y = 50; y < 250; y++)
//     {
//         for (int x = 50; x < 250; x++)
//         {
//             mlx_pixel_put(mlx, win, x, y, color2hex(color1));
//         }
//     }

//     for (int y = 350; y < 550; y++)
//     {
//         for (int x = 50; x < 250; x++)
//         {
//             mlx_pixel_put(mlx, win, x, y, color2hex(color2));
//         }
//     }

//     for (int y = 50; y < 250; y++)
//     {
//         for (int x = 350; x < 550; x++)
//         {
//             mlx_pixel_put(mlx, win, x, y, color2hex(added));
//         }
//     }

//     // Wait for events
//     mlx_loop(mlx);

//     return (0);
// }

#include "color.h"
#include "vector.h"
#include "world.h"
#include "mlx.h"    // minilibxのヘッダーファイル

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
    camera_vec = vector_init(0, 0, -5);  // スクリーンの少し手前な感じ

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
                my_mlx_pixel_put(&world->img, x, y, rgb2hex(255, 0, 0));
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
	mlx_loop(world.mlx_ptr);

	return (0);
}
