/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:17:51 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:34:29 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char	*str;

	if (s1 == NULL)
		return (NULL);
	str = (unsigned char *)s1;
	c &= 0xff;
	while (n-- > 0)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", memchr("\0abcde\0", '\0', 5));
	printf("%s\n", memchr("abcde\0", '\0', 5));
	printf("%s\n", memchr("abcdefgh", 'd', 3));
	printf("%s\n", memchr("abcdefgh", -159, 3));
	printf("%s\n", memchr("aaaaaaasdsss", 's', 10));
	printf("%s\n", ft_memchr("\0abcde\0", '\0', 5));
	printf("%s\n", ft_memchr("abcde\0", '\0', 5));
	printf("%s\n", ft_memchr("abcdefgh", 'd', 3));
	printf("%s\n", ft_memchr("abcdefgh", -159, 3));
	printf("%s\n", ft_memchr("aaaaaaasdsss", 's', 10));
}*/