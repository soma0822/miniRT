/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:52:39 by khorike           #+#    #+#             */
/*   Updated: 2023/09/13 12:54:29 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "color.h"
# include "vector.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "read_map.h"
# include "utils.h"
# include "parse.h"
# include "debug.h"
# include "mini_rt.h"

typedef struct s_matrix
{
	double	m[4][4];
}	t_matrix;

t_matrix	perspective_projection_matrix(t_camera *camera);
t_vector	transform_vector(t_matrix *matrix, t_vector v);

#endif