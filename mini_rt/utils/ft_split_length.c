/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:53:25 by soma              #+#    #+#             */
/*   Updated: 2023/09/10 18:53:47 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

int	ft_split_length(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return (0);
	while (split[i] != NULL)
		i++;
	return (i);
}