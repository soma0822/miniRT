/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:10:43 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:33:08 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
		|| ('0' <= c && c <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isalnum('A'));
	printf("%i", ft_isalnum('a'));
	printf("%i", ft_isalnum('Z'));
	printf("%i", ft_isalnum('z'));
	printf("%i", ft_isalnum('0'));
	printf("%i\n", ft_isalnum(' '));
	printf("%i", isalnum('A'));
	printf("%i", isalnum('a'));
	printf("%i", isalnum('Z'));
	printf("%i", isalnum('z'));
	printf("%i", isalnum('0'));
	printf("%i\n", isalnum(' '));
}*/