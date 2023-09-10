/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:51:12 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/23 14:20:34 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t len)
{
	unsigned char	*str;

	if (buf == NULL)
		return (NULL);
	c &= 0xff;
	str = (unsigned char *)buf;
	while (len-- > 0)
		*str++ = c;
	return (buf);
}
/*
int	main(void)
{
	char	str1[] = "0000000000";
	char	str2[] = "0000000000";

	printf("%s\n", memset(str1 + 3, 'c', 3));
	printf("%s\n", ft_memset(str2 + 3, 'c', 3));
	printf("%s\n", str1);
	printf("%s\n", str2);
}*/