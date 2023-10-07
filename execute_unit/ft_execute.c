/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:34:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/07 23:12:51 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

void	ft_save_fd(int *save_stdin, int *save_stdout)
{
	*save_stdin = dup(STDIN_FILENO);
	*save_stdout = dup(STDOUT_FILENO);
}

void	ft_restore_fd(int save_stdin, int save_stdout)
{
	dup2(save_stdin, STDIN_FILENO);
	dup2(save_stdout, STDOUT_FILENO);
	close(save_stdin);
	close(save_stdout);
}

int	ft_execute(t_cmd *cmd, t_list *envp)
{
	char	**env;
	int		exit_status;

	env = ft_lst_to_char(envp);
	exit_status = 0;
	if (ft_redaraction(cmd->redir_in.file, cmd->redir_in.type) == -1)
		return (1);
	if (ft_redaraction(cmd->redir_out.file, cmd->redir_out.type) == -1)
		return (1);
	if (cmd->args[0])
		exit_status = execve(cmd->args[0], cmd->args, env);
	ft_error(cmd->args[0], strerror(errno));
	exit(exit_status);
	return (1);
}
