/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:06:49 by elakhfif          #+#    #+#             */
/*   Updated: 2023/07/08 14:10:37 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

t_cmd	*split_cmd(char *input)
{
	t_cmd	*result;
	char	*temp;

	result = NULL;
	while (input && input[0])
	{
		temp = ft_substr(input, 0, words_count(input));
		result = add_cmd(result, temp);
		input = input + words_count(input);
		if (input[0] == '|')
			input++;
	}
	if (check_quoted(result) || check_separator(result))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

// int	main(int ac, char **av)
// {
// 	t_cmd	*cmd;
// 	int	err;
//
// 	err = 0;
// 	if (ac == 2 && av[1])
// 	{
// 		cmd = split_cmd(av[1]);
// 		printf("[whole command is]:\t%s\n", av[1]);
// 		while (cmd)
// 		{
// 			printf("[command is]:\t%s\n", cmd->cmd);
// 			if (!cmd->next)
// 				break ;
// 			cmd = cmd->next;
// 		}
// 	}
// 	return (0);
// }
