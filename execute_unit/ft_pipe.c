/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:15:39 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/17 12:11:06 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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
	int status = -1;
	
	fd_in = 0;
	tmp = cmds;
	while (cmds)
	{
		cmd = (t_cmd *)cmds->content;
		pipe(fd);
		// herdoc
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_in, STDIN_FILENO);
			if (fd_in)
				close(fd_in);				
			close(fd[0]);
			if (cmd->separator == PIPE)
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


	waitpid(pid, &status, 0);
	printf ("status: %d\n", status >> 8);
	while (tmp->next)
	{
		if (pid == waitpid(-1, &status, 0))
			printf ("status: %d\n", status >> 8);
		tmp = tmp->next;
	}
	
	return (status >> 8);
}

// int main (int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
	
// 	t_cmd cmd1 = {.args = (char *[]){"/bin/ls", 0}, .separator = END};
// 	// t_cmd cmd2 = {.args = (char *[]){"/usr/bin/head", 0}, .separator = PIPE};
// 	// t_cmd cmd3 = {.args = (char *[]){"/usr/bin/wc", "-l", 0}, .separator = END};
// 	t_list *cmds = ft_lstnew(&cmd1);
// 	// ft_lstadd_back(&cmds, ft_lstnew(&cmd2));
// 	// ft_lstadd_back(&cmds, ft_lstnew(&cmd3));
// 	ft_pipe(cmds, envp);
// 	return (0);
// }