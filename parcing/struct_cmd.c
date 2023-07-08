/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:09:56 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/19 02:10:47 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*add_cmd(t_cmd *cmd, char *input)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = (t_cmd *)malloc(sizeof(t_cmd));
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
