/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:07:49 by sinagaki          #+#    #+#             */
/*   Updated: 2023/05/18 18:31:28 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len + 1);
	return (dst);
}
