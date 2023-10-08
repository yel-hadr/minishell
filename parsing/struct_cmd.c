/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:09:56 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/08 09:11:04 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

t_cmd	*add_cmd(t_cmd *cmd, char *input)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
	if (!new)
		return (NULL);
	new->cmd = input;
	new->next = NULL;
	if (!cmd)
		return (new);
	tmp = cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (cmd);
}

t_cmd	*add_cmd_back(t_cmd **cmd, t_cmd *new)
{

	t_cmd	*tmp;

	if (!new)
		return (NULL);
	if (!*cmd)
	{
		*cmd = new;
		return (*cmd);
	}
	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (*cmd);
}

t_cmd	*new_cmd(char *cmd)
{
	t_cmd	*new;

	new = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->next = NULL;
	return (new);
}
