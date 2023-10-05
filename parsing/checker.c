/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:56:11 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/06 00:18:16 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	*get_separator(char *str)
{
	int		i;
	char	*result;

	i = 0;
	result = ft_calloc(sizeof(char), (ft_strlen(str) + 1));
	while (str && str[i])
	{
		if (ft_strchr("|", str[i]))
		{
			ft_strcpy(result, str + i + 1);
			return (result);
		}
		i++;
	}
	return (result);
}

int	check_separator(t_cmd *cmd)
{
	char	*tmp;

	while (cmd)
	{
		ft_strtrim(cmd->cmd, " ");
		tmp = get_separator(cmd->cmd);
		if (ft_strlen(tmp) == ft_strlen(cmd->cmd)
			|| ft_strchr(tmp, '|') || cmd->cmd[0] == '|'
			|| cmd->cmd[ft_strlen(cmd->cmd) - 1] == '|')
		{
			ft_putstr_fd("mish: syntax error near unexpected token `|'\n", 2);
			free(tmp);
			return (1);
		}
		free(tmp);
		cmd = cmd->next;
	}
	return (0);
}

int	check_redirections(t_cmd *cmd)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (cmd)
	{
		while (cmd->cmd[i])
		{
			if (ft_strchr("><", cmd->cmd[i]))
				index++;
			i++;
		}
		if ((index == 1 && ((cmd->cmd[0] == '>') || cmd->cmd[0] == '<')) || cmd->cmd[ft_strlen(cmd->cmd) - 1] == '>' || cmd->cmd[ft_strlen(cmd->cmd) - 1] == '<')
		{
			ft_putstr_fd("mish: syntax error near unexpected token `newline'\n", 2);
			return (1);
		}
		index = 0;
		cmd = cmd->next; 
	}
	return (0);
}

