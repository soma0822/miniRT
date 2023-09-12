/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:30:20 by khorike           #+#    #+#             */
/*   Updated: 2023/09/07 12:33:54 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strspn(const char *s1, const char *s2)
{
	size_t		count;

	count = 0;
	while (*s1)
	{
		if (ft_strchr(s2, *s1))
			count++;
		else
			break ;
		s1++;
	}
	return (count);
}

static size_t	ft_strcspn(const char *s1r, const char *s2r)
{
	const char	*s1 = s1r;
	const char	*s2;

	while (*s1)
	{
		s2 = s2r;
		while (*s2)
		{
			if (*s1 == *s2++)
				return (s1 - s1r);
		}
		s1++;
	}
	return (s1 - s1r);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last_token = NULL;
	char		*token;

	if (str != NULL)
		last_token = str;
	if (last_token == NULL || *last_token == '\0')
		return (NULL);
	last_token += ft_strspn(last_token, delim);
	token = last_token;
	last_token += ft_strcspn(last_token, delim);
	if (*last_token != '\0')
		*last_token++ = '\0';
	return (token);
}
