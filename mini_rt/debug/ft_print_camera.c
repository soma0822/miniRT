/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 22:11:05 by soma              #+#    #+#             */
/*   Updated: 2023/09/11 19:26:13 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	ft_print_camera(t_camera *camera)
{
	printf("camera\n");
	if (camera == NULL)
	{
		printf("  (null)");
		return ;
	}
	ft_print_vector(camera->pos);
	ft_print_vector(camera->dir);
	printf("  fov: %f\n", camera->fov);
}