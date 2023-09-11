/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:28:07 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:34:53 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	size_t			i;

	if (dst == NULL || src == NULL)
		return (NULL);
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	i = 0;
	if (dst > src)
	{
		while (len-- > 0)
			c_dst[len] = c_src[len];
	}
	else
	{
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char	mem1[] = "abcdefghijklmnopqrstuvwxyz";
	char	mem2[] = "abcdefghijklmnopqrstuvwxyz";

	memmove(mem1 + 3, mem1, 1);  //サイズ大きくした時のエラー処理がわからない
	ft_memmove(mem2 + 3, mem2, 1);
	printf("memmove    : %s\n", mem1);
	printf("ft_memmove : %s\n", mem2);
}*/