/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_redir_handler_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaccagn <dpaccagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:31:02 by dimioui           #+#    #+#             */
/*   Updated: 2022/04/25 14:03:41 by dpaccagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	fd_handler_util1(int oldfd, char *path, int flags[2])
{
	if (oldfd > 2)
		close(oldfd);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !flags[0])
		ft_perror(NDIR, path, 127);
	else if (!flags[0] && access(path, R_OK) == -1)
		ft_perror(NPERM, path, 126);
	return (0);
}

int	fd_handler_util2(int fd, char *path, struct stat path_stat)
{
	fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (fd == -1 && S_ISDIR(path_stat.st_mode))
		ft_perror(IS_DIR, path, 127);
	else if (fd == -1 && access(path, W_OK) == -1 && access(path, F_OK) == 0)
		ft_perror(NPERM, path, 126);
	return (fd);
}
