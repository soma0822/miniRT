/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:37:59 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:32:53 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	if (s == NULL)
		return ;
	str = (char *)s;
	i = 0;
	while (n-- > 0)
		str[i++] = '\0';
}
/*
int	main(void)
{
	int		i = 0;
	char	str1[] = "0000000000";
	char	str2[] = "0000000000";

	bzero(str1, 3);
	ft_bzero(str2, 3);
	while (i < 10)
	{
		write(1, &str1[i], 1);
		write(1, ":", 1);
		write(1, &str2[i], 1);
		write(1, "\n", 1);
		i++;
	}
}*/