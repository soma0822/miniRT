/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:45:21 by soma              #+#    #+#             */
/*   Updated: 2023/09/14 20:01:26 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	init_function(int (*function_array[7])(char **, t_world *))
{
	function_array[0] = &parse_ambient;
	function_array[1] = &parse_camera;
	function_array[2] = &parse_light;
	function_array[3] = &parse_sphere;
	function_array[4] = &parse_plane;
	function_array[5] = &parse_cylinder;
	function_array[6] = &parse_error;
	return (0);
}
