/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:41:54 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/23 14:30:32 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*ad;

	if (s == NULL)
		return (NULL);
	c &= 0xff;
	str = (char *)s;
	ad = NULL;
	while (*str != 0)
	{
		if (*str == c)
			ad = str;
		str++;
	}
	if (c == 0)
		return (str);
	return (ad);
}

/*
int	main(void)
{
	printf("%s\n", strrchr("abcdefg", 'c'));
	printf("%s\n", strrchr("abcdefg", 'h'));
	printf("%s\n", strrchr("abcdefg", ' '));
	printf("%s\n", strrchr("abcdefg", 'a'));
	printf("%s\n", strrchr("abcdefgabcdefg", 'c'));
	printf("%s\n", ft_strrchr("abcdefg", 'c'));
	printf("%s\n", ft_strrchr("abcdefg", 'h'));
	printf("%s\n", ft_strrchr("abcdefg", ' '));
	printf("%s\n", ft_strrchr("abcdefg", 'a'));
	printf("%s\n", ft_strrchr("abcdefgabcdefg", 'c'));
}*/