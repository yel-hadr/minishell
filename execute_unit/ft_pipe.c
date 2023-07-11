/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:15:39 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/18 23:48:44 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/*
	ft_pipe: execute the pipe and multiple pipe
	@cmds: the list of cmds
	@envp: the envp
	return: 0 if success, 1 if not
*/

static int ft_child(int *fd, int fd_in, t_cmd *cmds, t_list **envp)
{
  char **env = ft_lst_to_char(*envp);
  if (!is_cmd_exists(&cmds->args[0], env))
  {
    ft_error(cmds->args[0], "command not found");
    exit(127);
  }
  dup2(fd_in, STDIN_FILENO);
  if (fd_in)
    close(fd_in);			
  close(fd[0]);
  if (cmds->next)
    dup2(fd[1], STDOUT_FILENO);
  close(fd[1]);
  if (ft_execute(cmds , env))
    ft_error(cmds->args[0], strerror(errno));
  exit(EXIT_FAILURE);
  return (0);
}

int ft_pipe(t_cmd *cmds, t_list **envp)
{
  int fd[2];
  int fd_in;
  int pid;
  int status;
  t_cmd *tmp;

  fd_in = 0;
	tmp = cmds;


	while (cmds)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
      ft_child(fd, fd_in, cmds, envp);
		else
		{
			close(fd[1]);
			if (fd_in)
				close(fd_in);
			fd_in = fd[0];
    }
		cmds = cmds->next;
	}
	close(fd_in);
  waitpid(pid, &status, 0);
	while (tmp->next)
	{
		waitpid(-1, &status, 0);
		tmp = tmp->next;
	}
	
	return (status >> 8);
}
