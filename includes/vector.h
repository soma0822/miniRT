/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:17:32 by shunito           #+#    #+#             */
/*   Updated: 2023/09/07 16:00:28 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include "../libft/libft.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vector	vector_init(double x, double y, double z);
t_vector	vector_add(t_vector a, t_vector b);
t_vector	vector_sub(t_vector a, t_vector b);
t_vector	vector_mult(t_vector a, double scalar);

double		vector_dot(t_vector a, t_vector b);
t_vector	vector_cross(t_vector a, t_vector b);
double		vector_length(t_vector a);
t_vector	vector_normalize(t_vector a);
int			get_vector_from_str(t_vector *vec, char *str);

#endif
