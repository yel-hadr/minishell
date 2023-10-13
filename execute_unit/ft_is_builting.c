/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:44:35 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/13 02:24:06 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

static int	do_redir(int *in, int *out, t_cmd *cmd)
{
	ft_save_fd(in, out);
	if (ft_redaraction(cmd->redir_in.file, cmd->redir_in.type) == -1)
		return (1);
	if (ft_redaraction(cmd->redir_out.file, cmd->redir_out.type) == -1)
		return (1);
	return (0);
}

int	exec_builting(t_cmd *cmd, t_list **envp)
{
	int	save_stdin;
	int	save_stdout;
	int	status;

	status = 0;
	if (do_redir(&save_stdin, &save_stdout, cmd))
		return (-1);
	if (!ft_strcmp(cmd->args[0], "echo"))
		status = ft_echo(cmd->args);
	else if (!ft_strcmp(cmd->args[0], "cd"))
		status = ft_cd(cmd->args, *envp);
	else if (!ft_strcmp(cmd->args[0], "pwd"))
		status = ft_pwd();
	else if (!ft_strcmp(cmd->args[0], "export"))
		status = ft_export(cmd->args, *envp);
	else if (!ft_strcmp(cmd->args[0], "exit"))
		status = ft_exit(cmd->args);
	else if (!ft_strcmp(cmd->args[0], "env"))
		status = ft_env(*envp);
	else if (!ft_strcmp(cmd->args[0], "unset"))
		status = ft_unset(cmd->args, envp);
	else
		status = 127;
	ft_restore_fd(save_stdin, save_stdout);
	return (status);
}

int	is_builting(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	else if (!ft_strcmp(cmd, "cd"))
		return (1);
	else if (!ft_strcmp(cmd, "pwd"))
		return (1);
	else if (!ft_strcmp(cmd, "export"))
		return (1);
	else if (!ft_strcmp(cmd, "exit"))
		return (1);
	else if (!ft_strcmp(cmd, "env"))
		return (1);
	else if (!ft_strcmp(cmd, "unset"))
		return (1);
	return (0);
}
