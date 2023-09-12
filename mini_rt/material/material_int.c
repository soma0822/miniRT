/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:07:34 by khorike           #+#    #+#             */
/*   Updated: 2023/09/12 14:46:07 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_shader_params	material_init(t_color kdif, t_color kspe, double shininess)
{
	t_shader_params	material;

	material.kdif = kdif;
	material.kspc = kspe;
	material.shininess = shininess;
	return (material);
}

t_shader_params	calculate_nomal_and_light_dir(t_vector light_position,
	t_vector position, t_vector sphere_vec)
{
	t_shader_params	material;

	material.normal = vector_normalize(vector_sub(position, sphere_vec));
	material.light_dir = vector_normalize(vector_sub(light_position, position));
	material.kdif = color_init(0, 1.0, 0);
	material.kspc = color_init(0.3, 0.3, 0.3);
	material.shininess = SHININESS;
	return (material);
}

// int			set_square(t_world *world, char **params)
// {
// 	t_object	*object;
// 	t_vec3		point;
// 	double		side_size;
// 	t_vec3		normal;
// 	t_fcolor	fcolor;

// 	if (ptrarr_len((void**)params) != 4 ||
// 		get_vec3_from_str(&point, params[0]) == ERROR ||
// 		get_vec3_from_str(&normal, params[1]) == ERROR ||
// 		get_fcolor_from_rgbstr(&fcolor, params[3]) == ERROR)
// 		return (put_and_return_err("Square is Misconfigured"));
// 	side_size = ft_atof(params[2]);
// 	if (!(object = square_init(point, vec3_normalize(normal), side_size,
// 				material_init(fcolor,
// 								fcolor_init(0.3, 0.3, 0.3),
// 								SHININESS))) ||
// 		!(ft_lstadd_back_new(&world->objects, object)))
// 		return (put_and_return_err("failed malloc object"));
// 	return (0);
// }
