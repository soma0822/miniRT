/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:53:07 by soma              #+#    #+#             */
/*   Updated: 2023/09/14 20:01:13 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	parse_map(char *str, t_world *world)
{
	char	**split;
	char	element[6][3];
	int		(*function_array[7])(char **, t_world *);
	int		i;

	if (str == NULL)
		ft_error("Memory allocation error!\n");
	init_element(element);
	init_function(function_array);
	split = ft_split(str, ' ');
	if (split == NULL)
		ft_error("Memory allocation error!\n");
	if (split[0] == NULL)
		return (0);
	i = 0;
	while (ft_strncmp(split[0], element[i], 3) != 0 && i < 6)
		i++;
	function_array[i](split, world);
	ft_free_twod_array(split);
	free(str);
	return (0);
}
