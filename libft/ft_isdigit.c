/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:05:56 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:33:43 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isdigit('A'));
	printf("%i", ft_isdigit('a'));
	printf("%i", ft_isdigit('Z'));
	printf("%i", ft_isdigit('z'));
	printf("%i", ft_isdigit('0'));
	printf("%i", ft_isdigit('9'));
	printf("%i\n", ft_isdigit(' '));
	printf("%i", isdigit('A'));
	printf("%i", isdigit('a'));
	printf("%i", isdigit('Z'));
	printf("%i", isdigit('z'));
	printf("%i", isdigit('0'));
	printf("%i", isdigit('9'));
	printf("%i\n", isdigit(' '));
}*/