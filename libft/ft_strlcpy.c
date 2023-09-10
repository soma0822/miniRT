/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:18:11 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/23 14:37:52 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	if (dstsize <= 0)
	{
		while (src[i] != 0)
			i++;
		return (i);
	}
	while (src[i] != 0 && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	while (src[i] != 0)
		i++;
	return (i);
}
/*
int	main(void)
{
	char src1[] = "abcdefghi";
	char src2[] = "abcde";
	printf("1-ft : %lu\n%s\n", ft_strlcpy(src1, src2, 10), src1);
	printf("1 : %lu\n%s\n", strlcpy(src1, src2, 10), src1);

	char src3[] = "abcdefghi";
	char src4[] = "abcdefghijkl";
	printf("3 : %lu\n%s\n", strlcpy(src3, src4, 10), src3);
	printf("3-ft : %lu\n%s\n", ft_strlcpy(src3, src4, 10), src3);

	char src5[] = "abcdefghi";
	char src6[] = "abcdefghi";
	printf("5-ft : %lu\n%s\n", ft_strlcpy(src5, src6, 10), src5);
	printf("5 : %lu\n%s\n", strlcpy(src5, src6, 10), src5);

	char src7[] = "abcdefghi";
	char src8[] = "";
	printf("7 : %lu\n%s\n", strlcpy(src7, src8, 3), src7);
	printf("7-ft : %lu\n%s\n", ft_strlcpy(src7, src8, 3), src7);

	char src9[] = "abcdefghi";
	char src10[] = "gwujk";
	printf("9-ft : %lu\n%s\n", ft_strlcpy(src9, src10, 0), src9);
	printf("9 : %lu\n%s\n", strlcpy(src9, src10, 0), src9);
}*/