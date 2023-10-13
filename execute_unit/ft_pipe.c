/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:15:39 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/13 02:22:55 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

static int	ft_child(int *fd, int fd_in, t_cmd *cmds, t_list *envp)
{
	dup2(fd_in, STDIN_FILENO);
	if (fd_in)
		close(fd_in);
	close(fd[0]);
	if (cmds->next)
		dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (is_builting(cmds->args[0]))
		exit(exec_builting(cmds, &envp));
	if (!is_cmd_exists(&cmds->args[0], envp))
	{
		ft_error(cmds->args[0], "command not found");
		exit(127);
	}
	exit(ft_execute(cmds, envp));
	return (0);
}

static int	ft_wait_pid(int *status, t_cmd *tmp, int pid)
{
	int	sig_status;

	waitpid(pid, status, 0);
	while (tmp->next)
	{
		waitpid(-1, NULL, 0);
		tmp = tmp->next;
	}
	g_sig = 0;
	if (WIFSIGNALED(*status))
	{
		sig_status = *status >> 8;
		return (WEXITSTATUS(sig_status) + 128);
	}
	return (*status >> 8);
}

static int	ft_do_parent(int *fd, int fd_in)
{
	close(fd[1]);
	if (fd_in)
		close(fd_in);
	fd_in = fd[0];
	return (fd_in);
}

int	ft_pipe(t_cmd *cmds, t_list *envp)
{
	int		fd[2];
	int		fd_in;
	int		pid;
	int		status;
	t_cmd	*tmp;

	if (!cmds || !cmds->args || !*cmds->args)
		return (0);
	if (cmds->next == NULL && is_builting(cmds->args[0]))
		return (exec_builting(cmds, &envp));
	fd_in = 0;
	tmp = cmds;
	g_sig = 1;
	while (cmds)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
			ft_child(fd, fd_in, cmds, envp);
		else
			fd_in = ft_do_parent(fd, fd_in);
		cmds = cmds->next;
	}
	close(fd_in);
	return (ft_wait_pid(&status, tmp, pid));
}
