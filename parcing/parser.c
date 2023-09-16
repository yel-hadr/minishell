/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/16 04:17:19 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

t_cmd	*parser(char *line, t_list *env)
{
	t_cmd	*result;
	t_cmd	*cmd;
	char *tmp;

	tmp = expand_variable(line, env);
	result = split_cmd(tmp);
	cmd = result;
	while (cmd)
	{
		cmd->args = split_args(cmd->cmd, cmd);
		cmd = cmd->next;
	}
	return (result);
}


