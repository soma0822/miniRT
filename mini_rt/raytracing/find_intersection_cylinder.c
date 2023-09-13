/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_cylinder.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:22:42 by soma              #+#    #+#             */
/*   Updated: 2023/09/13 22:28:24 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

t_shader_params *find_intersection_cylinder(t_world *world, t_object *object, t_ray ray)
{
    t_vector dir_vec;
    t_vector oc;
    t_shader_params *ret;
    double a;
    double b;
    double c;
    double d;
    ret = NULL;

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
        ret = shader_init(vector_add(ray.start, vector_mult(dir_vec, t1)), *object, *world, vector_length(vector_mult(dir_vec, t1)));
        ret->normal = vector_normalize(vector_sub(ret->position, vector_mult(*object->pos, hit_point)));
    }

    hit_point = vector_dot(dir_vec, *object->dir) * t2 + vector_dot(oc, *object->dir);

    if (t2 >= 0 && hit_point >= 0 && hit_point <= object->height)
    {
        ret = shader_init(vector_add(ray.start, vector_mult(dir_vec, t2)), *object, *world, vector_length(vector_mult(dir_vec, t2)));
        ret->normal = vector_normalize(vector_sub(ret->position, vector_mult(*object->pos, hit_point)));
    }

    return (ret);
}