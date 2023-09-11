/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:07:41 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/20 12:18:30 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_m(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_putnbr_m(n, fd);
}

void	ft_putnbr_m(int n, int fd)
{
	char	c;

	if (n > 9 || n < -9)
	{
		ft_putnbr_m(n / 10, fd);
		n %= 10;
	}
	if (n < 0)
		n = -n;
	c = n + '0';
	write(fd, &c, 1);
}
/*
int	main(void)
{
	ft_putnbr_fd(INT32_MIN, 1);
	ft_putnbr_fd(INT32_MAX, 1);
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(100390, 1);
}*/