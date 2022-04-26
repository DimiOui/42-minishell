/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 01:27:51 by jsemel            #+#    #+#             */
/*   Updated: 2022/04/26 08:27:45 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;
	size_t		old_len;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	if (ft_strchri_gnl(buf[fd], '\n') == -1)
	{
		old_len = ft_strlen_gnl(buf[fd]);
		buf[fd] = expand_buffer(buf[fd], fd);
		if (old_len == ft_strlen_gnl(buf[fd]) && buf[fd])
			line = ft_substr_gnl(buf[fd], 0, ft_strlen_gnl(buf[fd]));
	}
	if (!buf[fd])
		return (NULL);
	if (!line && ft_strchri_gnl(buf[fd], '\n') != -1)
		line = ft_substr_gnl(buf[fd], 0, ft_strchri_gnl(buf[fd], '\n') + 1);
	if (line)
	{
		buf[fd] = reduce_buff(buf[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}

char	*reduce_buff(char *buf, char *line)
{
	char	*newbuf;
	int		line_len;

	if (!buf || !line)
		return (buf);
	line_len = ft_strlen_gnl(line);
	if ((int)ft_strlen_gnl(buf) == line_len)
	{
		free(buf);
		return (NULL);
	}
	newbuf = ft_substr_gnl(buf, line_len, ft_strlen_gnl(buf) - line_len);
	free(buf);
	return (newbuf);
}

char	*expand_buffer(char *buf, int fd)
{
	char	*newbuf;
	int		newlen;
	char	*aux;

	aux = get_newline(fd);
	if (!aux)
		return (NULL);
	if (!aux[0])
	{
		free(aux);
		return (buf);
	}
	if (!buf)
		return (aux);
	newlen = ft_strlen_gnl(buf) + ft_strlen_gnl(aux);
	newbuf = malloc(newlen + 1);
	if (!newbuf)
		return (NULL);
	ft_strlcpy_gnl(newbuf, buf, newlen + 1);
	ft_strlcat_gnl(newbuf, aux, newlen + 1);
	free(buf);
	free(aux);
	return (newbuf);
}

char	*get_newline(int fd)
{
	char	*aux;
	int		nbytes;

	aux = malloc(BUFFER_SIZE + 1);
	if (!aux)
		return (NULL);
	nbytes = read(fd, aux, BUFFER_SIZE);
	if (nbytes < 0)
	{
		free(aux);
		return (NULL);
	}
	aux[nbytes] = '\0';
	return (aux);
}
