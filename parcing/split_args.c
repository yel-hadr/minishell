/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/13 06:05:00 by yel-hadr         ###   ########.fr       */
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

	count = 0;
	while (*cmd)
	{
		if (ft_strchr("><", cmd[0]))
		{
			while (ft_strchr("><", cmd[0]))
				cmd++;
			count--;
		}
		else if (!ft_strchr("\t |", cmd[0]))
		{
			count++;
			cmd = next_arg(cmd);
		}
		else
			cmd++;
	}
	return (count);
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
		if (ft_strchr("><", *cmd))
		{
			while (ft_strchr("\t ><", cmd[0]))
				cmd++;
			tmp = ft_substr(cmd, 0,
					(ft_strlen(cmd) - ft_strlen(next_arg(cmd))));
			printf ("\n{tmp = %s}\n", remove_quotes(tmp));
			
		}
		else
		{
			tmp = ft_substr(cmd, 0,
					(ft_strlen(cmd) - ft_strlen(next_arg(cmd))));
			result[index++] = remove_quotes(tmp);
			free(tmp);
		}
		printf ("tmp = %s\n", tmp);
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
