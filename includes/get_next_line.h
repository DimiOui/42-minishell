/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:59:42 by aperez-b          #+#    #+#             */
/*   Updated: 2022/04/26 08:27:44 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
int		ft_strchri_gnl(const char *s, int c);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
char	*reduce_buff(char *buf, char *line);
char	*expand_buffer(char *buf, int fd);
char	*get_newline(int fd);

#endif
