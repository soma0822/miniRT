/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:23:20 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/16 11:59:41 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

static void	map_error_check(t_world *world);
static int	is_dark(t_world *world);

t_world	*read_map(char *file_name)
{
	int		fd;
	char	*line;
	t_world	*world;

	world = (t_world *)ft_calloc(sizeof(t_world), 1);
	if (world == NULL)
		ft_error("Memory allocation error!\n");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("File open error!\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (parse_map(ft_strtrim(line, "\n"), world) == 1)
			ft_error("Map error!\n");
		free(line);
	}
	close(fd);
	map_error_check(world);
	return (world);
}

static void	map_error_check(t_world *world)
{
	if (!world->camera)
	{
		system("leaks -q miniRT");
		ft_error("Map error!\n");
	}
	else if (!world->ambient && !world->light)
		ft_error("Map error!\n");
	else if (!world->ambient)
	{
		world->ambient = (t_ambient *)ft_calloc(sizeof(t_ambient), 1);
		if (world->ambient == NULL)
			ft_error("Memory allocation error!\n");
		world->ambient->ratio = 0;
		world->ambient->color = parse_color("0,0,0");
	}
	if (is_dark(world))
		ft_error("Completely in the dark!\n");
}

static int	is_dark(t_world *world)
{
	t_ambient	*amb;
	t_light		*light;

	amb = world->ambient;
	light = world->light;
	if ((!amb || amb->ratio == 0.0
			|| (amb->color->b == 0 && amb->color->g == 0 && amb->color->r == 0))
		&& (!light || light->ratio == 0.0)
		&& world->objects)
		return (1);
	return (0);
}
