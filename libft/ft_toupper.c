/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:55:21 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/17 21:28:52 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c + 'A' - 'a');
	return (c);
}
/*
int	main(void)
{
	printf("%c", toupper('a'));
	printf("%c", ft_toupper('a'));
	printf("%c", toupper('Z'));
	printf("%c", ft_toupper('Z'));
	printf("%c", toupper('z'));
	printf("%c", ft_toupper('z'));
	printf("%c", toupper('{'));
	printf("%c", ft_toupper(123));
	printf("%c", toupper(32));
	printf("%c", ft_toupper(32));
}*/