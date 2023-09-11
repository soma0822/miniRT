/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:45:07 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/23 14:56:08 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	int				i;

	if (n == 0)
		return (dst);
	if (dst == NULL || src == NULL)
		return (NULL);
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	i = 0;
	while (n-- > 0)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
/*
int main(void)
{
	unsigned char mem1[]  = {0x12, 0x34, 0x56, 0x78};
	unsigned char mem2[5] = {0xff, 0xff, 0xff, 0xff, 0xff};

	ft_memcpy(mem2, mem1, sizeof(mem1));

	printf("mem2[]:%x %x %x %x %x \n", mem2[0], mem2[1], mem2[2], mem2[3], mem2[4]);

	return 0;
}*/