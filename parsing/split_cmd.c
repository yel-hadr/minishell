/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:06:49 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/13 07:44:06 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	check_quotes_loop(char *str)
{
	int		i;
	int    sq;
	int    dq;

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

static int    check_quoted(t_cmd *cmd)
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

static int    words_count(char *input)
{
	int    count;
	int    sq;
	int    dq;

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

void    skip_wspaces(char *input, int *i)
{
	while (input[*i] == ' ' || input[*i] == '\t')
		(*i)++;
}

t_cmd    *split_cmd(char *input)
{
	t_cmd 		*cmd;
	int			i;
	int			j;

	i = 0;
	cmd = NULL;
	skip_wspaces(input, &i);
	if (input[i] == '|')
		return (free(cmd), NULL);
	while (input && input[i])
	{
		j = words_count(input + i);
		add_cmd_back(&cmd, new_cmd(ft_substr(input, i, j)));
		i += j;
		if (input[i] == '|' && i++)
		{
			skip_wspaces(input, &i);
			if (!input[i] || input[i] == '|')
			{
				ft_putstr_fd(TOKENERR, 2);
				return (free_cmd(cmd), NULL);
			}
		}
	}
	if (check_quoted(cmd))
		return (free(cmd), NULL);
	return (cmd);
}
