/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redaraction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:06:50 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/09/09 08:30:22 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"


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

int redaraction_heredoc(char *herdoc)
{
  int fd;
  int pipefd[2];

  pipe(pipefd);
  write(pipefd[1], herdoc, ft_strlen(herdoc));
  close(pipefd[1]);
  fd = pipefd[0];
  dup2(fd, STDIN_FILENO);
  close(fd);
  return (fd);
}

int ft_redaraction(char *file, t_redir_type redaraction)
{
  if (redaraction == REDIR_IN)
    return (redaraction_input(file));
  else if (redaraction == REDIR_OUT)
    return (redaraction_output(file));
  else if (redaraction == APPEND)
    return (redaraction_append(file));
  else if (redaraction == HEREDOC)
    return (redaraction_heredoc(file));
  return (-1);
}

