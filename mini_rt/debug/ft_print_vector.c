/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:16:07 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 22:16:36 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_vector(t_vector *vector)
{
	printf("  vector");
	printf("  x: %f", vector->x);
	printf("  y: %f", vector->y);
	printf("  z: %f\n", vector->z);
}