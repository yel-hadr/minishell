/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redaraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:06:50 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/15 09:49:22 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"


/*
	ft_redaraction: redaraction the input or the output
	@file: the file
	@redaraction: the redaraction type
	@return: the fd of the file
*/

static int redaraction_input(char *file)
{
	int fd;

	fd = open(file, O_RDONLY , 0644);
	if (fd > -1)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (fd);
}

static int redaraction_output(char *file)
{
	int fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd > -1)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (fd);
}

static int redaraction_append(char *file)
{
	int fd ;
	
	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd > -1)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (fd);
}

char *redaraction_heredoc(char *str)
{
	char *line;
	char *herdoc;


	while (1)
	{
		line = readline("> ");
		if (!ft_strncmp(line, str, ft_strlen(str)))
		{
			free(line);
			break ;
		}
		line = ft_strjoin(line, "\n");
		herdoc = ft_strjoin(herdoc, line);
		free(line);
	}

	return (herdoc);
}

int ft_redaraction(char *file, t_redir redaraction)
{
	int fd;
	
	if (redaraction == REDIR_INPUT)
		fd = redaraction_input(file);
	else if (redaraction == REDIR_OUTPUT)
		fd = redaraction_output(file);
	else if (redaraction == REDIR_APPEND)
		fd = redaraction_append(file);
	else
		fd = -1;
	return (fd);
}