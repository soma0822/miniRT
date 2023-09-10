/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:38:20 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/10 22:24:35 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	main(int ac, char **av)
{
	t_world	*world;
	
	if (ac != 2)
		ft_error("Argument error!\n");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 3, ".rt", 3))
		ft_error("File extension error!\n");
	world = read_map(av[1]);
	if (world == NULL)
		return (ft_error("Map error!\n"));
	ft_print_world(world);
	exit(0);
}