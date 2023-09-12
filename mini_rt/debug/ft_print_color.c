/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:11:40 by soma              #+#    #+#             */
/*   Updated: 2023/09/11 19:26:36 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_color(t_color *color)
{
	if (color == NULL)
	{
		printf("  color: (null)");
		return ;
	}
	printf("  color: %d,%d,%d\n", (int)(color->r * 255), (int)(color->g * 255), (int)(color->b * 255));
	printf("  color: %f,%f,%f\n", color->r, color->g, (color->b));
}