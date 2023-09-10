/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:30:26 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/18 18:29:30 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isprint(167));
	printf("%i", ft_isprint('a'));
	printf("%i", ft_isprint('Z'));
	printf("%i", ft_isprint('z'));
	printf("%i", ft_isprint('0'));
	printf("%i", ft_isprint('9'));
	printf("%i\n", ft_isprint(' '));
	printf("%i", isprint(167));
	printf("%i", isprint('a'));
	printf("%i", isprint('Z'));
	printf("%i", isprint('z'));
	printf("%i", isprint('0'));
	printf("%i", isprint('9'));
	printf("%i\n", isprint(' '));
}*/