/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:15:48 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/17 21:31:20 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isascii(167));
	printf("%i", ft_isascii('a'));
	printf("%i", ft_isascii('Z'));
	printf("%i", ft_isascii('z'));
	printf("%i", ft_isascii('0'));
	printf("%i", ft_isascii('9'));
	printf("%i\n", ft_isascii(' '));
	printf("%i", isascii(167));
	printf("%i", isascii('a'));
	printf("%i", isascii('Z'));
	printf("%i", isascii('z'));
	printf("%i", isascii('0'));
	printf("%i", isascii('9'));
	printf("%i\n", isascii(' '));
}*/
