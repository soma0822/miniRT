/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:51:37 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:33:58 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_num_dig(int n);
void	ft_rev(char *num, size_t i);

char	*ft_itoa(int n)
{
	size_t	num_dig;
	size_t	i;
	char	*num;

	i = 0;
	num_dig = ft_num_dig(n);
	if (n <= 0)
		num_dig++;
	num = malloc(num_dig + 1);
	if (num == NULL)
		return (NULL);
	if (n == 0)
		num[i++] = '0';
	while (n != 0)
	{
		if (n < 0)
			num[i++] = -(n % 10) + '0';
		else
			num[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (i < num_dig)
		num[i++] = '-';
	ft_rev(num, i - 1);
	return (num);
}

size_t	ft_num_dig(int n)
{
	size_t	num_dig;

	num_dig = 0;
	while (n)
	{
		num_dig++;
		n = n / 10;
	}
	return (num_dig);
}

void	ft_rev(char *num, size_t i)
{
	size_t	j;
	char	dst;

	j = 0;
	while (j <= i / 2)
	{
		dst = num[j];
		num[j] = num[i - j];
		num[i - j] = dst;
		j++;
	}
	num[i + 1] = 0;
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
}*/
