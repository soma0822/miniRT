/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:52:10 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/21 19:04:51 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				cmp;
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	cmp = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((s1[i] != 0 || s2[i] != 0) && n > 0)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		cmp = c1 - c2;
		if (cmp != 0)
			return (cmp);
		i++;
		n--;
	}
	return (cmp);
}
/*
int	main(void)
{
	printf("%d\n", strncmp(NULL, "abc", 0));
	printf("%d\n", strncmp("abcdefgh", "defgh", 10));
	printf("%d\n", strncmp("abcdefgh", "hsaaad", 10));
	printf("%d\n", ft_strncmp("abcdefgh", "a", 8));
	printf("%d\n", ft_strncmp("abcdefgh", "abcd", 10));
	printf("%d\n", ft_strncmp("abcdefgh", "abc", 3));
	printf("%d\n", ft_strncmp("abcdefgh", "defgh", 10));
	printf("%d\n", ft_strncmp("abcdefgh", "hsaaad", 10));
}*/