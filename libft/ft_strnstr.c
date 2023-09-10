/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:44:22 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/23 21:52:05 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_dst;
	int		i;

	if (needle == NULL || *needle == 0)
		return ((char *)haystack);
	if (haystack == NULL)
		return (NULL);
	if (len == 0)
		return (0);
	while (*haystack != 0 && len-- > 0)
	{
		if (*haystack == *needle)
		{
			i = 1;
			len_dst = len;
			while (*(haystack + i) == *(needle + i)
				&& len_dst-- > 0 && *(needle + i) != 0)
				i++;
			if (*(needle + i) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
/*
int main(void)
{
	printf("%s\n", strnstr(0, 0, 5));
	printf("%s\n", ft_strnstr(NULL, "cdefg", 0));
	printf("%s\n", strnstr("abcdefgajda", "cdefg", 7));
	printf("%s\n", strnstr("aaaaabcdefgggg", "cdefg", 20));
	printf("%s\n", strnstr("aaaadddaaaaddd", "aaaddd", 5));
	printf("%s\n", ft_strnstr(0, 0, 5));
	printf("%s\n", ft_strnstr(NULL, "cdefg", 10));
	printf("%s\n", ft_strnstr("abcdefgajda", "cdefg", 7));
	printf("%s\n", ft_strnstr("aaaaabcdefgggg", "cdefg", 20));
	printf("%s\n", ft_strnstr("aaaadddaaaaddd", "aaaddd", 5));
}*/