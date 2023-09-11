/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:04:38 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/20 14:49:47 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				cmp;
	int				i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (n-- > 0)
	{
		cmp = str1[i] - str2[i];
		if (cmp != 0)
			return (cmp);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", memcmp("\0abcd\0abcd", "\0abcd\0abcd", 10));
	printf("%d\n", memcmp("\0abcz\0abcd", "\0abcd\0", 6));
	printf("%d\n", memcmp("\0abcd\0abcd", "\0abce\0abcd", 10));
	printf("%d\n", memcmp("\0abcd", "\0abcd\0abcd", 5));
	printf("%d\n", memcmp("\0abcd\0abcd", "\0abcd\0abcd", 0));
	printf("%d\n", ft_memcmp("\0abcd\0abcd", "\0abcd\0abcd", 10));
	printf("%d\n", ft_memcmp("\0abcz\0abcd", "\0abcd\0", 6));
	printf("%d\n", ft_memcmp("\0abcd\0abcd", "\0abce\0abcd", 10));
	printf("%d\n", ft_memcmp("\0abcd", "\0abcd\0abcd", 5));
	printf("%d\n", ft_memcmp("\0abcd\0abcd", "\0abcd\0abcd", 0));
}*/