/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:24:18 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/10 22:00:50 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include "include.h"
# include "mini_rt.h"

t_world	*read_map(char *file_name);
void	init_element(char element[6][3]);
int		parse_map(char *str, t_world *world);
int	init_function(int (*function_array[7])(char **, t_world *));


#endif