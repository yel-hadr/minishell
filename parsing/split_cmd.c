/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:06:49 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/09 00:40:11 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	check_quotes_loop(char *str)
{
	int	i;
	int	sq;
	int	dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (str[i])
	{
		if (str[i] == '\'' && !dq)
			sq = !sq;
		if (str[i] == '\"' && !sq)
			dq = !dq;
		i++;
	}
	return (sq || dq);
}

static int	check_quoted(t_cmd *cmd)
{
	while (cmd)
	{
		if (check_quotes_loop(cmd->cmd))
		{
			ft_putstr_fd("mish: Warning: quotes not closed\n", 2);
			free(cmd->cmd);
			return (1);
		}
		if (!cmd->next)
			break ;
		else
			cmd = cmd->next;
	}
	return (0);
}

static int	words_count(char *input)
{
	int	count;
	int	sq;
	int	dq;

	count = 0;
	sq = 0;
	dq = 0;
	while (input && input[count])
	{
		if (input[count] == '\'' && !dq)
			sq = !sq;
		if (input[count] == '\"' && !sq)
			dq = !dq;
		if (input[count] == '|' && !sq && !dq)
			return (count);
		count++;
	}
	return (count);
}

t_cmd	*split_cmd(char *input, int *status)
{
	t_cmd	*cmd;
	t_cmd	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cmd = NULL;
	while (input && input[i])
	{
		j = words_count(input + i);
		tmp = new_cmd(ft_substr(input, i, j));
		add_cmd_back(&cmd, tmp);
		i += j;
		if (input[i] == '|')
		{
			i++;
			if (!input[i])
			{
				ft_putstr_fd("mish: syntax error near unexpected token `|'\n",
					2);
				*status = 1;
				free_cmd(cmd);
				return (NULL);
			}
		}
	}
	if (check_quoted(cmd))
	{
		*status = 1;
		free(cmd);
		return (NULL);
	}
	return (cmd);
}
