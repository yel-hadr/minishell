/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:46:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/13 07:43:30 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static void	init_cmd(t_cmd *cmd)
{
	cmd->args = NULL;
	cmd->redir_in.file = NULL;
	cmd->redir_out.file = NULL;
	cmd->redir_in.type = NONE;
	cmd->redir_out.type = NONE;
}

static int	expand_cmd(t_cmd **result, char **line, t_list *env, int *status)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ft_strchr(*line, '$') && !ft_strchr(*line, '\''))
	{
		tmp = expand_variable(*line, env, status);
		*line = tmp;
		i = 1;
	}
	*result = split_cmd(*line);
	if (*result)
		i = 1;
	return (i);
}

t_cmd	*parser(char *line, t_list *env, int *status)
{
	t_cmd	*result;
	t_cmd	*tmp;

	g_sig = -1;
	if (!line || *line == '\0')
		return (NULL);
	result = NULL;
	if (!expand_cmd(&result, &line, env, status))
		ft_putstr_fd(TOKENERR, 2);
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
