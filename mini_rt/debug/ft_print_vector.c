/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:16:07 by soma              #+#    #+#             */
/*   Updated: 2023/09/11 19:27:19 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_vector(t_vector *vector)
{
	printf("  vector");
	if (vector == NULL)
	{
		printf("  (null)");
		return ;
	}
	printf("  x: %f", vector->x);
	printf("  y: %f", vector->y);
	printf("  z: %f\n", vector->z);
}