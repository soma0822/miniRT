/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:15:52 by soma              #+#    #+#             */
/*   Updated: 2023/09/12 17:05:41 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include "include.h"

void	init_element(char element[6][3])
{
	ft_strlcpy(element[0], "A", 3);
	ft_strlcpy(element[1], "C", 3);
	ft_strlcpy(element[2], "L", 3);
	ft_strlcpy(element[3], "sp", 3);
	ft_strlcpy(element[4], "pl", 3);
	ft_strlcpy(element[5], "cy", 3);
}
