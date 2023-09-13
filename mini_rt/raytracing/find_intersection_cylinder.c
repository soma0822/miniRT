/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_cylinder.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:22:42 by soma              #+#    #+#             */
/*   Updated: 2023/09/13 13:49:09 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params *find_intersection_cylinder(t_world *world, t_object *object, t_ray ray)
{
    t_vector dir_vec;
    t_vector oc;
    double a;
    double b;
    double c;
    double d;

    dir_vec = ray.direction;
    oc = vector_sub(ray.start, *object->pos);
    a = vector_dot(dir_vec, dir_vec) - pow(vector_dot(dir_vec, *object->dir), 2);
    b = 2 * (vector_dot(dir_vec, oc) - vector_dot(dir_vec, *object->dir) * vector_dot(oc, *object->dir));
    c = vector_dot(oc, oc) - pow(vector_dot(oc, *object->dir), 2) - pow(object->diameter / 2, 2);
    d = pow(b, 2) - 4 * a * c;

    if (d < 0)
        return (NULL);

    double t1 = (-b - sqrt(d)) / (2 * a);
    double t2 = (-b + sqrt(d)) / (2 * a);

    // 交点が円柱の高さの範囲内にあるかチェック
    double hit_point = vector_dot(dir_vec, *object->dir) * t1 + vector_dot(oc, *object->dir);

    if (t1 >= 0 && hit_point >= 0 && hit_point <= object->height)
    {
        return (shader_init(vector_add(ray.start, vector_mult(dir_vec, t1)), *object, *world, vector_length(vector_mult(dir_vec, t1))));
    }

    hit_point = vector_dot(dir_vec, *object->dir) * t2 + vector_dot(oc, *object->dir);

    t_vector position = vector_add(ray.start, vector_mult(dir_vec, t2));
    if (t2 >= 0 && hit_point >= 0 && hit_point <= object->height)
    {
        return (shader_init(position, *object, *world,vector_length(vector_mult(dir_vec, t2))));
    }

    return (NULL);
}