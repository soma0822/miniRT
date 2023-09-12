/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinagaki <sinagaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:10 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/11 18:36:26 by sinagaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		s1_len;
	size_t		dst_len;
	const char	*tmp_beginning;
	const char	*tmp_end;
	char		*dst;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	tmp_beginning = s1;
	tmp_end = s1 + s1_len - 1;
	while (ft_strchr(set, (int)*tmp_beginning) && *tmp_beginning)
		tmp_beginning++;
	if (*tmp_beginning == 0)
		dst_len = 1;
	else
	{
		while (ft_strchr(set, (int)*tmp_end) && tmp_end != tmp_beginning)
			tmp_end--;
		dst_len = tmp_end - tmp_beginning + 2;
	}
	dst = malloc(dst_len);
	if (dst)
		ft_strlcpy(dst, tmp_beginning, dst_len);
	return (dst);
}
/*
void	ft_setdele(char *dst, const char *set, size_t len);
void	ft_setdeler(char *dst, const char *set, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	dst = malloc(len_s1 + 1);
	if (dst == NULL)
		return (NULL);
	if (s1 == NULL || set == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, len_s1 + 1);
	ft_setdele(dst, set, len_s1);
	ft_setdeler(dst, set, ft_strlen(dst));
	return (dst);
}

void	ft_setdele(char *dst, const char *set, size_t len)
{
	int	i;

	i = 0;
	if (*dst == 0)
		return ;
	while (set[i] != 0 && len > 0)
	{
		if (*dst == set[i])
		{
			ft_memmove(dst, dst + 1, len);
			i = 0;
			len--;
		}
		else
			i++;
	}
}

void	ft_setdeler(char *dst, const char *set, size_t len)
{
	size_t	i;

	i = 0;
	if (*dst == 0)
		return ;
	while (set[i] != 0 && len > 0)
	{
		if (dst[len - 1] == set[i])
		{
			dst[len - 1] = 0;
			i = 0;
			len--;
		}
		else
			i++;
	}
}

int	main(void)
{
	printf("%s", ft_strtrim("         ", " "));
}*/