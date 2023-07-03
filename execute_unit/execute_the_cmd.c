/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_the_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:34:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/19 11:27:52 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

// int ft_herdoc(t_execute *cmd)
// {
// 	if (cmd->cmd->redir_in.redir == REDIR_HEREDOC)
// 	{
// 		pipe(cmd->herdoc_fd);
// 		write(cmd->herdoc_fd[1], cmd->cmd->redir_in.file, ft_strlen(cmd->cmd->redir_in.file));
// 		close(cmd->herdoc_fd[1]);
// 		dup2(cmd->herdoc_fd[0], STDIN_FILENO);
// 		close(cmd->herdoc_fd[0]);
// 	}
// 	return (0);
// }

int ft_execute(t_execute *cmd, char **envp)
{
	
	if (cmd->cmd->redir_in.redir == REDIR_HEREDOC)
		ft_herdoc(cmd);
	else if (cmd->cmd->redir_in.redir != NONE)
		ft_redaraction(cmd->cmd->redir_in.file, cmd->cmd->redir_in.redir);
	if (cmd->cmd->redir_out.redir)
		ft_redaraction(cmd->cmd->redir_out.file, cmd->cmd->redir_out.redir);
	if (cmd->cmd->args[0])
		execve(cmd->cmd->args[0], cmd->cmd->args, envp);
	return (1);
}

void ft_save_fd(t_execute *cmd)
{
	cmd->save_stdin = dup(STDIN_FILENO);
	cmd->save_stdout = dup(STDOUT_FILENO);
}

void ft_restore_fd(t_execute *cmd)
{
	dup2(cmd->save_stdin, STDIN_FILENO);
	dup2(cmd->save_stdout, STDOUT_FILENO);
	close(cmd->save_stdin);
	close(cmd->save_stdout);
}

int ft_builting(t_execute *cmd, char **args, t_list **envp)
{
	ft_save_fd(cmd);
	if (cmd->cmd->redir_in.redir == REDIR_HEREDOC)
		ft_herdoc(cmd);
	else if (cmd->cmd->redir_in.redir != NONE)
		ft_redaraction(cmd->cmd->redir_in.file, cmd->cmd->redir_in.redir);
	if (cmd->cmd->redir_out.redir)
		ft_redaraction(cmd->cmd->redir_out.file, cmd->cmd->redir_out.redir);
	
	if (ft_strnstr(args[0], "echo", ft_strlen(args[0])))
		cmd->status = ft_echo(args);
	else if (ft_strnstr(args[0], "cd", ft_strlen(args[0])))
		cmd->status = ft_cd(args, envp);
	else if (ft_strnstr(args[0], "pwd", ft_strlen(args[0])))
		cmd->status = ft_pwd();
	else if (ft_strnstr(args[0], "export", ft_strlen(args[0])))
		cmd->status = ft_export(args, envp);
	else if (ft_strnstr(args[0], "exit", ft_strlen(args[0])))
		cmd->status = ft_exit(args);
	ft_restore_fd(cmd);
	return (0);
}

int ft_execute_the_cmd(t_execute *cmd, char **envp)
{
	if (cmd->cmd->args[0])
	{
		t_list *tmp;
		tmp = ft_dupenvp(envp);
		if (is_builting(cmd->cmd->args[0]))
			return (ft_builting(cmd, cmd->cmd->args, &tmp));
		else
			return (ft_execute(cmd, envp));
	}
	return (0);
}

