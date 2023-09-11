/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:59:30 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:35:16 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || *s == 0)
		return ;
	write(fd, s, ft_strlen(s));
}
/*
int	main(void)
{
	ft_putstr_fd(NULL, 1);
}*/