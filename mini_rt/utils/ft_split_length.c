/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:53:25 by soma              #+#    #+#             */
/*   Updated: 2023/09/14 14:27:44 by khorike          ###   ########.fr       */
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
