/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:26:38 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:36:34 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}
/*
int	main(void)
{
	printf("%c", tolower('a'));
	printf("%c", ft_tolower('a'));
	printf("%c", tolower('Z'));
	printf("%c", ft_tolower('Z'));
	printf("%c", tolower('A'));
	printf("%c", ft_tolower('A'));
	printf("%c", tolower('{'));
	printf("%c", ft_tolower(123));
	printf("%c", tolower(32));
	printf("%c", ft_tolower(32));
}*/