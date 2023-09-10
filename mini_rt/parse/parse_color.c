/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:54:51 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:45:12 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

static int	color_check(char *str);

t_color	*parse_color(char *str)
{
	t_color	*color;
	char	**split;

	color = ft_calloc(sizeof(t_color), 1);
	if (color == NULL)
		ft_error("Memory allocation error!\n");
	if (color_check(str) == 1)
		ft_error("Color error!\n");
	split = ft_split(str, ',');
	if (split == NULL)
		ft_error("Memory allocation error!\n");
	if (ft_split_length(split) != 3)
		ft_error("Color error!\n");
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	ft_free_twod_array(split);
	return (color);
}

static int	color_check(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ',')
		{
			printf("%s\n", str);
			printf("str[%d]: %i\n", i, str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}