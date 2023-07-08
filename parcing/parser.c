/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/26 06:27:46 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*parser(char *line)
{
	t_cmd	*result;
	t_cmd	*cmd;

	result = split_cmd(line);
	cmd = result;
	while (cmd)
	{
		cmd->args = split_args(cmd->cmd);
		cmd = cmd->next;
	}
	return (result);
}


