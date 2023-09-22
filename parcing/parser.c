/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/20 07:02:13 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

t_cmd	*parser(char *line, t_list *env, int *status)
{
	t_cmd	*result;
	t_cmd	*cmd;

	g_sig = -1;
	result = split_cmd(line, status);
	cmd = result;
	while (cmd)
	{
		cmd->args = split_args(cmd->cmd, cmd, env);
		cmd = cmd->next;
	}
	return (result);
}


