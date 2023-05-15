/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:23:16 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/15 16:10:16 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

int	ft_pipe(t_cmd **ptr, t_env env)
{
	(void)env;
	int e_status;
	t_cmd *cmd;
	int pid;
	int tmp_fd;
	int fd[2];
	
	e_status = 0;
	tmp_fd = -1;
	cmd = *ptr;
	while (cmd)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			if (tmp_fd == -1)
			{
				tmp_fd = 0;
				dup2(tmp_fd, STDIN_FILENO);
				close(tmp_fd);
			}
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			//excut()
			// if (exuc() == -1)
			// 	strerror(errno);
		}
		else
		{
			wait(NULL);
			tmp_fd = fd[0];
		}
		cmd = cmd->next;
	}
	return (e_status);
}
