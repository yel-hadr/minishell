/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/11 13:35:23 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	*next_arg(char *cmd)
{
	int	i;
	int	sq;
	int	dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (cmd[i] && (cmd[i] != ' ' || sq || dq))
	{
		if (cmd[i] == '\'' && !dq)
			sq = !sq;
		else if (cmd[i] == '\"' && !sq)
			dq = !dq;
		i++;
	}
	return (cmd + i);
}

static int	args_count(char *cmd)
{
	int	count;
	int	i;
	int	sq;
	int	dq;

	count = 0;
	i = 0;
	sq = 0;
	dq = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' && !dq)
			sq = !sq;
		else if (cmd[i] == '\"' && !sq)
			dq = !dq;
		else if (cmd[i] == ' ' && !sq && !dq)
			count++;
		i++;
	}
	if (cmd[i - 1] != ' ')
		count++;
	return (count);
}

static char	*next_quote(char *cmd)
{
	int	i;
	int	sq;
	int	dq;

	i = 1;
	sq = 0;
	dq = 0;
	while (cmd[i] && (cmd[i] != '\'' || sq || dq))
	{
		if (cmd[i] == '\'' && !dq)
			sq = !sq;
		else if (cmd[i] == '\"' && !sq)
			dq = !dq;
		i++;
	}
	return (cmd + i);
}

char	**split_args(char *cmd)
{
	int		index;
	int		count;
	char	*tmp;
	char	**result;

	index = 0;
	count = args_count(cmd);
	result = ft_calloc(count + 1, sizeof(char *));
	while (index < count)
	{
		while (cmd[0] && ft_strchr("\t ", cmd[0]))
			cmd++;
		if (ft_strchr("\'\"", cmd[0]))
		{
			tmp = ft_substr(cmd, 0, next_quote(cmd) - cmd);
			result[index++] = remove_quotes(tmp);
			free(tmp);
		}
		else
		{
			tmp = ft_substr(cmd, 0, next_arg(cmd) - cmd); // next_arg(cmd) - cmd = strlen of the word
			result[index++] = remove_quotes(tmp);
			free(tmp);
		}
		cmd = next_arg(cmd);
	}
	result[index] = NULL;
	return (result);
}

// int	main(void)
// {
// 	char	*cmd;
// 	char	**args;
// 	int		i;
//
// 	cmd = "echo \"hello world\" > file";
// 	args = split_args(cmd);
// 	i = 0;
// 	while (args[i])
// 	{
// 		printf("%s\n", args[i]);
// 		i++;
// 	}
// 	return (0);
// }
