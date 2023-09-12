/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:27:24 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:35:12 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dst_count(char const *s, char c);
char	**ft_cut(char const *s, char c, char **dst, int i);
int		ft_split_strlen(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	dst_count;

	if (s == NULL)
		return (NULL);
	dst_count = ft_dst_count(s, c);
	dst = malloc(sizeof(char *) * (dst_count + 1));
	if (dst == NULL)
		return (NULL);
	ft_cut(s, c, dst, 0);
	return (dst);
}

size_t	ft_dst_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s != 0)
				s++;
		}
		else
			s++;
	}
	return (count);
}

void	ft_free_all(char **dst, int i)
{
	while (i-- > 0)
		free(dst[i]);
}

char	**ft_cut(char const *s, char c, char **dst, int i)
{
	int	word_count;

	while (*s == c && *s != 0)
		s++;
	if (*s == 0)
	{
		dst[i] = NULL;
		return (dst);
	}
	else
	{
		word_count = ft_split_strlen(s, c);
		dst[i] = malloc(word_count + 1);
		if (dst[i] == NULL)
		{
			ft_free_all(dst, i);
			free(dst);
			return (NULL);
		}
		ft_strlcpy(dst[i], s, word_count + 1);
		return (ft_cut(s + word_count, c, dst, i + 1));
	}
}

int	ft_split_strlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != 0 && s[count] != c)
		count++;
	return (count);
}
/*
int	main(void)
{
	char	**str;
	int		i = -1;
	str = ft_split("hello,world,42,tokyo", ' ');
	while (str[++i] != NULL)
		printf("%s\n", str[i]);
}*/