/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection_cylinder.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:22:42 by soma              #+#    #+#             */
/*   Updated: 2023/09/14 13:44:31 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

// t_shader_params *find_intersection_cylinder(t_world *world, t_object *object, t_ray ray)
// {
//     t_vector dir_vec;
//     t_vector oc;
//     t_shader_params *ret;
//     double a;
//     double b;
//     double c;
//     double d;
//     ret = NULL;

//     dir_vec = ray.direction;
//     oc = vector_sub(ray.start, *object->pos);
//     a = vector_dot(dir_vec, dir_vec) - pow(vector_dot(dir_vec, *object->dir), 2);
//     b = 2 * (vector_dot(dir_vec, oc) - vector_dot(dir_vec, *object->dir) * vector_dot(oc, *object->dir));
//     c = vector_dot(oc, oc) - pow(vector_dot(oc, *object->dir), 2) - pow(object->diameter / 2, 2);
//     d = pow(b, 2) - 4 * a * c;

//     if (fabs(d) < EPSILON)
//         return (NULL);

//     double t1 = (-b - sqrt(d)) / (2 * a);
//     double t2 = (-b + sqrt(d)) / (2 * a);

//     // 交点が円柱の高さの範囲内にあるかチェック
//     double hit_point = vector_dot(dir_vec, *object->dir) * t1 + vector_dot(oc, *object->dir);

//     if (t1 >= 0 && hit_point >= 0 && hit_point <= object->height)
//     {
//         ret = shader_init(vector_add(ray.start, vector_mult(dir_vec, t1)), *object, *world, vector_length(vector_mult(dir_vec, t1)));
//         ret->normal = vector_normalize(vector_sub(ret->position, vector_mult(*object->pos, hit_point)));
//     }

//     hit_point = vector_dot(dir_vec, *object->dir) * t2 + vector_dot(oc, *object->dir);

//     if (t2 >= 0 && hit_point >= 0 && hit_point <= object->height)
//     {
//         ret = shader_init(vector_add(ray.start, vector_mult(dir_vec, t2)), *object, *world, vector_length(vector_mult(dir_vec, t2)));
//         ret->normal = vector_normalize(vector_sub(ret->position, vector_mult(*object->pos, hit_point)));
//     }

//     return (ret);
// }

t_shader_params *find_intersection_cylinder(t_world *world, t_object *object, t_ray ray)
{
    t_vector dir_vec;
    t_vector oc;
    t_shader_params *ret1, *ret2;
    double a, b, c, d;

    dir_vec = ray.direction;
    oc = vector_sub(ray.start, *object->pos);
    a = vector_dot(dir_vec, dir_vec) - pow(vector_dot(dir_vec, *object->dir), 2);
    b = 2 * (vector_dot(dir_vec, oc) - vector_dot(dir_vec, *object->dir) * vector_dot(oc, *object->dir));
    c = vector_dot(oc, oc) - pow(vector_dot(oc, *object->dir), 2) - pow(object->diameter / 2, 2);
    d = pow(b, 2) - 4 * a * c;

    if (fabs(d) < EPSILON) {
        return (NULL);
    }

    double t1 = (-b - sqrt(d)) / (2 * a);
    double t2 = (-b + sqrt(d)) / (2 * a);

    ret1 = NULL;
    ret2 = NULL;

    // t1での交点を計算
    double hit_point1 = vector_dot(dir_vec, *object->dir) * t1 + vector_dot(oc, *object->dir);
    if (t1 >= EPSILON && hit_point1 > EPSILON && hit_point1 <= object->height) {
        ret1 = shader_init(vector_add(ray.start, vector_mult(dir_vec, t1)), *object, *world, vector_length(vector_mult(dir_vec, t1)));
        
        t_vector intersection_to_center = vector_sub(ret1->position, *object->pos);
        t_vector projected = vector_mult(*object->dir, vector_dot(intersection_to_center, *object->dir));
        ret1->normal = vector_normalize(vector_sub(intersection_to_center, projected));
    }
    
    // t2での交点を計算
    double hit_point2 = vector_dot(dir_vec, *object->dir) * t2 + vector_dot(oc, *object->dir);
    if (t2 >= EPSILON && hit_point2 > EPSILON && hit_point2 <= object->height) {
        ret2 = shader_init(vector_add(ray.start, vector_mult(dir_vec, t2)), *object, *world, vector_length(vector_mult(dir_vec, t2)));
    
        t_vector intersection_to_center = vector_sub(ret2->position, *object->pos);
        t_vector projected = vector_mult(*object->dir, vector_dot(intersection_to_center, *object->dir));
        ret2->normal = vector_normalize(vector_sub(intersection_to_center, projected));
    }


    // 両方のtが有効な場合、より小さいtを持つ交点を採用
    if (ret1 && ret2) {
        if (t1 < t2) {
            // ret2を解放（もしshader_initが動的にメモリを確保している場合）
            free(ret2);
            return ret1;
        } else {
            // ret1を解放（もしshader_initが動的にメモリを確保している場合）
            free(ret1);
            return ret2;
        }
    }

    if (ret1) return ret1;
    if (ret2) return ret2;

    return NULL;
}


// 円柱の中心線上の点を正確に特定することを目指しています。
// 具体的には、交点から円柱の中心線までのベクトルを取得し、
// そのベクトルから円柱の方向ベクトルの成分を除去します。

// intersection_to_center: 
// 交点から円柱の底面の中心へのベクトルを計算します。

// projected:
// 上記のベクトル上で、円柱の方向ベクトルの成分を求めます。
// これは、交点から円柱の中心軸上の点へのベクトルの計算に使用されます。
// 最後のステップで、intersection_to_centerからprojectedを引くことで、
// 円柱の側面の正確な法線ベクトルを得られます。