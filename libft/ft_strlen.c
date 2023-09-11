/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:37:07 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/23 14:33:23 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
/*
int	main(void)
{
	printf("%lu\n", strlen("abcdefghijklmnopqrstuvwxyz"));
	printf("%lu\n", ft_strlen("abcdefghijklmnopqrstuvwxyz"));
	printf("%lu\n", strlen(" "));
	printf("%lu\n", ft_strlen(" "));
	printf("%lu\n", strlen("020-5739-2819"));
	printf("%lu\n", ft_strlen("020-5739-2819"));
	printf("%lu\n", strlen("  42Tokyo @roppongi"));
	printf("%lu\n", ft_strlen("  42Tokyo @roppongi"));
}*/