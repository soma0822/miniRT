/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:46:45 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:36:17 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;
	size_t	len_s;

	if (s == NULL || f == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	dst = malloc(len_s + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	ft_strlcpy(dst, s, len_s + 1);
	while (dst[i] != 0)
	{
		dst[i] = (*f)(i, dst[i]);
		i++;
	}
	return (dst);
}
/*
char	ft_c(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	*str = ft_strmapi("abcde", &ft_c);
	printf("%s", str);
	free(str); 
}
*/