/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:41:41 by khorike           #+#    #+#             */
/*   Updated: 2023/09/11 15:43:00 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

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

typedef struct s_material
{
	t_color	kdif;
	t_color	kspe;
	float	shininess;
}	t_material;

#endif