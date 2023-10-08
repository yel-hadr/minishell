/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/08 08:51:20 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

//free_cmd frees the cmd struct
void	free_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		*cmd = tmp->next;
		free(tmp->cmd);
		free(tmp->args);
		free(tmp);
		tmp = *cmd;
	}
}

t_cmd	*parser(char *line, t_list *env, int *status)
{
	t_cmd	*result;
	t_cmd	*tmp;
	char	*tmp2;

	g_sig = -1;
	if (!line)
		return (NULL);
	if (ft_strchr(line, '$'))
	{
		tmp2 = expand_variable(line, env, status);
		line = tmp2;
	}
	result = split_cmd(line, status);
	tmp = result;
	while (tmp)
	{
		*status = split_args(tmp, env);
		tmp = tmp->next;
	}
	free_cmd(&tmp);
	free(line);
	return (result);
}
