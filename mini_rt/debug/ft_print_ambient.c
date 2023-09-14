/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:09:30 by soma              #+#    #+#             */
/*   Updated: 2023/09/14 19:57:10 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_ambient(t_ambient *ambient)
{
	printf("ambient\n");
	if (ambient == NULL)
	{
		printf("  (null)");
		return ;
	}
	printf("  ratio: %f\n", ambient->ratio);
	ft_print_color(ambient->color);
}
