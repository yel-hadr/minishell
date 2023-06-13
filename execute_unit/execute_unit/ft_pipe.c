/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:08:43 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/13 20:32:24 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipe.h"

/*
	ft_pipe: execute the pipe and multiple pipe
	@cmds: the list of cmds
	@envp: the envp
	return: 0 if success
*/



int ft_pipe(t_list *cmds, char **envp)
{
	int pid;
	int fd[2];
	int fd_in;
	t_cmd *cmd;
	t_list *tmp;
	// int status;
	
	fd_in = 0;
	tmp = cmds;
	while (cmds)
	{
		cmd = (t_cmd *)cmds->content;
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_in, STDIN_FILENO);
			if (fd_in)
				close(fd_in);				
			close(fd[0]);
			if (cmd->type == PIPE)
				dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			if (ft_execute(*cmd , envp))
				ft_error(cmd->args[0], strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
		{
			close(fd[1]);
			if (fd_in)
				close(fd_in);
			fd_in = fd[0];
			cmds = cmds->next;
		}
	}
	close(fd_in);
	while (tmp)
	{
		waitpid(-1, NULL, 0);
		tmp = tmp->next;
	}
	
	return (0);
}