/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:41:13 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:35:36 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = malloc(len_s1 + len_s2 + 1);
	if (dst == NULL)
		return (NULL);
	if (len_s1 + len_s2 == 0)
	{
		*dst = 0;
		return (dst);
	}
	ft_strlcpy(dst, s1, len_s1 + 1);
	ft_strlcpy(&dst[len_s1], s2, len_s2 + 1);
	return (dst);
}
/*
int	main(void)
{
	printf("%s", ft_strjoin("", ""));
}
*/