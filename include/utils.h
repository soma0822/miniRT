/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:44:40 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/10 21:57:57 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "include.h"

double	ft_atof(char *nbr);
int	ft_error(char *error_mes);
void	ft_free_twod_array(char **array);
int	ft_isspace(char c);
void	ft_lstadd_back(t_object **lst, t_object *new_lst);
int	ft_split_length(char **split);


#endif