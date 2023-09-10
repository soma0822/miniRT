/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:04:59 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/21 19:05:17 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL || *s == 0)
	{
		write(fd, "\n", 1);
		return ;
	}
	write(fd, s, 1);
	ft_putendl_fd(s + 1, fd);
}
/*
int	main(void)
{
	ft_putendl_fd("akjshdfj", 1);
}*/