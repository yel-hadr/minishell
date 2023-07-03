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
	return: 0 if success
*/

int ft_herdoc(t_execute *cmd)
{
	if (cmd->cmd->redir_in.redir == REDIR_HEREDOC)
	{
		pipe(cmd->herdoc_fd);
		write(cmd->herdoc_fd[1], cmd->cmd->redir_in.file, ft_strlen(cmd->cmd->redir_in.file));
		close(cmd->herdoc_fd[1]);
		dup2(cmd->herdoc_fd[0], STDIN_FILENO);
		close(cmd->herdoc_fd[0]);
	}
	return (0);
}

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
				printf ("command not found: %s\n", execute.cmd->args[0]);
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

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_list *cmds;
	t_cmd *cmd;
	t_cmd *cmd1;
	t_cmd *cmd2;
	t_list *envp;

	cmd = malloc(sizeof(t_cmd));
	cmd1 = malloc(sizeof(t_cmd));
	cmd2 = malloc(sizeof(t_cmd));
	cmd->args = malloc(sizeof(char *) * 3);
	cmd1->args = malloc(sizeof(char *) * 3);
	cmd2->args = malloc(sizeof(char *) * 3);
	cmd->args[0] = strdup("ls");
	cmd->args[1] = strdup("-l");
	cmd->args[2] = NULL;
	cmd1->args[0] = strdup("grep");
	cmd1->args[1] = strdup("ft");
	cmd1->args[2] = NULL;
	cmd2->args[0] = strdup("wc");
	cmd2->args[1] = strdup("-l");
	cmd2->args[2] = NULL;
	cmd->separator = PIPE;
	cmd1->separator = PIPE;
	cmd2->separator = END;
	cmds = ft_lstnew(cmd);
	ft_lstadd_back(&cmds, ft_lstnew(cmd1));
	ft_lstadd_back(&cmds, ft_lstnew(cmd2));
	envp = ft_lstnew(ft_strdup("PATH=/bin"));
	ft_pipe(cmds, &envp);
	return (0);
	
}
