/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_sphere.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:43:11 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/13 13:47:45 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params *find_intersection_sphere(t_world *world, t_object *object, t_ray ray)
{
	// t_intersection *intersection;

	// intersection = ft_calloc(sizeof(t_intersection), 1);
	// if (!intersection)
	// 	ft_error("Memory allocation error!\n");
	t_vector dir_vec;
	dir_vec = ray.direction;
	t_vector camera2sphere_vec = vector_sub(ray.start, *object->pos);
	double a = vector_length(dir_vec) * vector_length(dir_vec);
	double b = 2 * vector_dot(camera2sphere_vec, dir_vec);
	double c = vector_dot(camera2sphere_vec, camera2sphere_vec) - (object->diameter / 2) * (object->diameter / 2);
	double d = b * b - 4 * a * c;
	double t1 = (-b - sqrt(d)) / (2 * a);
	double t2 = (-b + sqrt(d)) / (2 * a);

    if (t1 >= 0)
    {
        return (shader_init(vector_add(ray.start, vector_mult(dir_vec, t1)), *object, *world, vector_length(vector_mult(dir_vec, t1))));
    }
    
	t_vector position = vector_add(ray.start, vector_mult(dir_vec, t2));
    if (t2 >= 0)
	{
        return (shader_init(position, *object, *world, vector_length(vector_mult(dir_vec, t2))));
	}
    return (NULL);
}