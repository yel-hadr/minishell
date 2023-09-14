/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/14 07:24:33 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

t_cmd	*parser(char *line)
{
	t_cmd	*result;
	t_cmd	*cmd;

	result = split_cmd(line);
	cmd = result;
	while (cmd)
	{
		cmd->args = split_args(cmd->cmd, cmd);
		printf ("\ncmd->cmd = %s\n", cmd->cmd);
		printf ("cmd->args[0] = %s\n", cmd->args[0]);
		printf ("cmd->redir_out.type = %d\n", cmd->redir_out.type);
		printf ("cmd->redir_out.file = %s\n", cmd->redir_out.file);
		printf ("cmd->redir_in.type = %d\n", cmd->redir_in.type);
		printf ("cmd->redir_in.file = %s\n", cmd->redir_in.file);

		cmd = cmd->next;
	}
	return (result);
}


