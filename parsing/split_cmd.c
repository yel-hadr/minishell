/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:06:49 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/07 23:29:36 by yel-hadr         ###   ########.fr       */
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
	t_cmd	*result;
	char	*tmp;

	result = NULL;
	while (input && *input)
	{
		tmp = ft_substr(input, 0, words_count(input));
		result = add_cmd(result, tmp);
		input = input + words_count(input);
		if (*input == '|')
		{
			input++;
			if (!*input)
				result = add_cmd(result, "|");
		}
	}
	if (check_quoted(result) || check_redirections(result)
		|| check_separator(result))
	{
		*status = 1;
		free(result);
		return (NULL);
	}
	else
		*status = 0;
	return (result);
}
