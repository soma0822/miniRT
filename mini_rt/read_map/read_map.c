/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:23:20 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/10 22:49:30 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

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
		if (parse_map(line, world) == 1)
			ft_error("Map error!\n");
	}
	close(fd);
	return (world);
}