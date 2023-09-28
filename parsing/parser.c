/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/28 22:42:04 by elakhfif         ###   ########.fr       */
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
		tmp2 = ft_strdup(line);
		free(line);
		line = tmp2;
	}
	result = NULL;
	if (ft_strchr("\n \t", *line))
		line = ft_strtrim(line, "\n \t");
	tmp = result;
	while (tmp)
	{
		split_args(tmp, env);
		tmp = tmp->next;
	}
	if (line[0] != '\0')
		result = split_cmd(line, status);
	return (result);
}


