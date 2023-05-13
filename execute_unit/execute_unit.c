/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:54:26 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/13 01:12:25 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

#define READ_END 0
#define WRITE_END 1

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
				dup2(tmp_fd, STDIN_FILENO);
				close(tmp_fd);
			}
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
			//excut()
		}
		else
		{
			wait(NULL);			
			tmp_fd = fd[0];
		}
	}
		cmd = cmd->next;
	return (e_status);
}

int execute_unit(t_list *env, t_cmd *cmd)
{
	(void)env;
	int e_status;
	t_cmd *curr;

	e_status = 0;
	curr = cmd;
	while (cmd)
	{
		
		cmd = cmd->next;
	}
	return (e_status);
}

int main (int ac, char *av[], char *aenv[])
{
	(void)av;
	(void)ac;
	t_list *env;

	env = ft_creat_env(aenv);
	printf("%s\n", search_env(av[1], env));
}
