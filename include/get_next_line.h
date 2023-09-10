/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soma <soma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:36:26 by sinagaki          #+#    #+#             */
/*   Updated: 2023/09/10 17:24:45 by soma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*read_file(char *dst, int fd);
char	*get_next(char *buffer);
char	*get_line(char *buffer);
char	*ft_free(char *dst, char *tmp);

#endif