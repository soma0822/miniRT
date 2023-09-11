/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:44:38 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:35:49 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dst;
	size_t	i_src;
	size_t	reva;

	i_src = ft_strlen(src);
	if (dst == NULL)
		return (i_src);
	i_dst = ft_strlen(dst);
	if (i_dst < dstsize)
		reva = i_dst + i_src;
	else
		return (i_src + dstsize);
	i_dst = 0;
	i_src = 0;
	while (dst[i_dst] != 0 && i_dst < dstsize)
		i_dst++;
	while (src[i_src] != 0 && i_dst + 1 < dstsize)
	{
		dst[i_dst] = src[i_src];
		i_dst++;
		i_src++;
	}
	dst[i_dst] = 0;
	return (reva);
}
/*
int	main(void)
{
	char src1[100] = "abcdefghi";
	char src2[] = "abcdefghijkl";
	printf("1-ft : %lu\n%s\n", strlcat(src1, NULL, 5), src1);
	printf("1 : %lu\n%s\n", strlcat(src1, src2, 10), src1);

	char src3[100] = "abcdefghi";
	char src4[] = "abcdefghijkl";
	printf("3 : %lu\n%s\n", ft_strlcat(src3, NULL, 5), src3);
	printf("3-ft : %lu\n%s\n", ft_strlcat(src3, src4, 10), src3);

	char src5[] = "abcdefghi";
	char src6[] = "abcdefghi";
	printf("5-ft : %lu\n%s\n", ft_strlcat(src5, src6, 10), src5);
	printf("5 : %lu\n%s\n", ft_strlcat(src5, src6, 10), src5);

	char src7[] = "abcdefghi";
	char src8[] = "";
	printf("7 : %lu\n%s\n", strlcat(src7, src8, 3), src7);
	printf("7-ft : %lu\n%s\n", ft_strlcat(src7, src8, 3), src7);

	char src9[30] = "abcdefghi";
	char src10[] = "gwujk";
	printf("9-ft : %lu\n%s\n", ft_strlcat(src9, src10, 20), src9);
	printf("9 : %lu\n%s\n", ft_strlcat(src9, src10, 20), src9);
}
*/