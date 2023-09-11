/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:28:24 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/23 14:31:04 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (*str != 0)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == 0)
		return (str);
	return (0);
}
/*
int	main(void)
{
	char *s = "libft-test-tokyo";
	printf("%s\n", strchr(s, 0));
	printf("%s\n", strchr(s, 'l' - 256));
	printf("%s\n", strchr(s, 'l' + 256));
	printf("%s\n", strchr(s, 'a'));
	printf("%s\n", strchr(s, 'c'));
	printf("%s\n", ft_strchr(s, 0));
	printf("%s\n", ft_strchr(s, 'l' - 256));
	printf("%s\n", ft_strchr(s, 'l' + 256));
	printf("%s\n", ft_strchr(s, 'a'));
	printf("%s\n", ft_strchr(s, 'c'));
}*/