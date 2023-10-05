/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/05 15:33:28 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

t_cmd	*parser(char *line, t_list *env, int *status)
{
	t_cmd	*result;
	t_cmd	*tmp;
	char	*tmp2;

	*status = 0;
	g_sig = -1;
	if (ft_strchr(line, '$'))
	{
		tmp2 = expand_variable(line, env);
		free(line);
		line = tmp2;
	}
	result = split_cmd(line, status);
	tmp = result;
	while (tmp)
	{
		split_args(tmp, env);
		tmp = tmp->next;
	}
	return (result);
}


