/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:06:49 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/16 19:49:23 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_separator(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

static int	words_count(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '|')
			count++;
		i++;
	}
	return (count + 1);
}

t_cmd	*add_cmd(t_cmd *cmd, char *input)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->cmd = input;
	new->next = NULL;
	if (!cmd)
		return (new);
	tmp = cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (cmd);
}

t_cmd	*split_cmd(char *input, int *error)
{
	int	i;
	t_cmd	*cmd;
	char	*tmp;

	i = 0;
	cmd = NULL;
	while (input[i])
	{
		tmp = ft_substr(input, i, ft_strlen(input));
		if (check_separator(tmp))
		{
			cmd = add_cmd(cmd, ft_substr(tmp, 0, ft_strchr(tmp, '|') - tmp));
			i += ft_strchr(tmp, '|') - tmp + 1;
		}
		else
		{
			cmd = add_cmd(cmd, ft_substr(tmp, 0, ft_strlen(tmp)));
			i += ft_strlen(tmp);
		}
	}
	return (cmd);
}

// int	main(int ac, char **av)
// {
// 	t_cmd	*cmd;
// 	int	error;
//
// 	error = 0;
// 	cmd = split_cmd(av[1], &error);
// 	if (error)
// 		printf("error\n");
// 	while (cmd)
// 	{
// 		printf("%s\n", cmd->cmd);
// 		cmd = cmd->next;
// 	}
// 	return (0);
// }
