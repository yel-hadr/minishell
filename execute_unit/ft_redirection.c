/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:06:50 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/10 03:19:20 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

static int	redaraction_input(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd > -1)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
		close(STDIN_FILENO);
	return (fd);
}

static int	redaraction_output(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd > -1)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else
		close(STDOUT_FILENO);
	return (fd);
}

static int	redaraction_append(char *file)
{
	int	fd ;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd > -1)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else
		close(STDOUT_FILENO);
	return (fd);
}

int	redaraction_heredoc(char *herdoc)
{
	int	fd;
	int	pipefd[2];

	pipe(pipefd);
	write(pipefd[1], herdoc, ft_strlen(herdoc));
	close(pipefd[1]);
	fd = pipefd[0];
	if (fd >= 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
		close(STDIN_FILENO);
	return (fd);
}

int	ft_redaraction(char *file, t_redir_type redaraction)
{
	if (redaraction == REDIR_IN)
		return (redaraction_input(file));
	else if (redaraction == REDIR_OUT)
		return (redaraction_output(file));
	else if (redaraction == APPEND)
		return (redaraction_append(file));
	else if (redaraction == HEREDOC)
		return (redaraction_heredoc(file));
	else if (redaraction == NONE)
		return (0);
	return (-1);
}
