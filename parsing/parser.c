/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/13 05:31:13 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	init_cmd(t_cmd *cmd)
{
	cmd->args = NULL;
	cmd->redir_in.file = NULL;
	cmd->redir_out.file = NULL;
	cmd->redir_in.type = NONE;
	cmd->redir_out.type = NONE;
}

t_cmd	*parser(char *line, t_list *env, int *status)
{
	t_cmd	*result;
	t_cmd	*tmp;
	char	*tmp2;

	g_sig = -1;
	if (!line)
		return (NULL);
	if (ft_strchr(line, '$') && !ft_strchr(line, '\''))
	{
		tmp2 = expand_variable(line, env, status);
		line = tmp2;
	}
	result = split_cmd(line, status);
	tmp = result;
	while (tmp)
	{
		init_cmd(tmp);
		*status = split_args(tmp, env);
		tmp = tmp->next;
	}
	free(line);
	if (g_sig == -1)
		g_sig = 0;
	return (result);
}
