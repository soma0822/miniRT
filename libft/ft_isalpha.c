/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:37:13 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:33:20 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isalpha('A'));
	printf("%i", ft_isalpha('a'));
	printf("%i", ft_isalpha('Z'));
	printf("%i", ft_isalpha('z'));
	printf("%i", ft_isalpha('0'));
	printf("%i\n", ft_isalpha(' '));
	printf("%i", isalpha('A'));
	printf("%i", isalpha('a'));
	printf("%i", isalpha('Z'));
	printf("%i", isalpha('z'));
	printf("%i", isalpha('0'));
	printf("%i\n", isalpha(' '));
}*/