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

/*
int ft_pipe(t_list *cmds, t_list **envp)
{
	t_execute	execute;
	execute.fd_in = 0;
	execute.tmp = cmds;

	
	while (cmds)
	{
		execute.cmd = (t_cmd *)cmds->content;
		pipe(execute.fd);
		execute.pid = fork();
		if (execute.pid == 0)
		{
			if (!is_cmd_exists(&execute.cmd->args[0], ft_lst_to_char(*envp)))
			{
				ft_error(execute.cmd->args[0], "command not found");
				exit(127);
			}
			dup2(execute.fd_in, STDIN_FILENO);
			if (execute.fd_in)
				close(execute.fd_in);				
			close(execute.fd[0]);
			if (execute.cmd->separator == PIPE)
				dup2(execute.fd[1], STDOUT_FILENO);
			close(execute.fd[1]);
			if (ft_execute(&execute , ft_lst_to_char(*envp)))
				ft_error(execute.cmd->args[0], strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
		{
			close(execute.fd[1]);
			if (execute.fd_in)
				close(execute.fd_in);
			execute.fd_in = execute.fd[0];
			cmds = cmds->next;
		}
	}
	close(execute.fd_in);
	waitpid(execute.pid, &execute.status, 0);
	printf ("status: %d\n", execute.status >> 8);
	while (execute.tmp->next)
	{
		if (execute.pid == waitpid(-1, &execute.status, 0))
			printf ("status: %d\n", execute.status >> 8);
		execute.tmp = execute.tmp->next;
	}
	
	return (execute.status >> 8);
}
*/

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

int main(int argc, char **argv, char **envp)
{
  t_cmd *cmds;
  t_list *env;
  int i;

  i = 0;
  env = NULL;
  cmds = malloc(sizeof(t_cmd));
  env = ft_dupenvp(envp);
  cmds->args = malloc(sizeof(char *) * 3);
  cmds->args[0] = ft_strdup("ls");
  cmds->args[1] = ft_strdup("-l");
  cmds->args[2] = NULL;
  cmds->next = malloc(sizeof(t_cmd));
  cmds->next->args = malloc(sizeof(char *) * 3);
  cmds->next->args[0] = ft_strdup("ls");
  cmds->next->args[1] = ft_strdup("-la");
  cmds->next->args[2] = NULL;
  cmds->next->next = malloc(sizeof(t_cmd));
  cmds->next->next->args = malloc(sizeof(char *) * 3);
  cmds->next->next->args[0] = ft_strdup("ls");
  cmds->next->next->args[1] = ft_strdup("-l");
  cmds->next->next->args[2] = NULL;
  cmds->next->next->next = NULL;
  ft_pipe(cmds, &env);
  return (0);
}





