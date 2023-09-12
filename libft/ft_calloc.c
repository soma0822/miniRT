/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:44:23 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:33:02 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (size != 0 && __LONG_LONG_MAX__ / size < count)
		return (NULL);
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
