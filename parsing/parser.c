/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/09 04:14:52 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

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
		*status = split_args(tmp, env);
		tmp = tmp->next;
	}
	free(line);
	if (g_sig == -1)
		g_sig = 0;
	return (result);
}
