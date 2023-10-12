/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/12 05:37:55 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static char	*ft_do_args(char *cmd, int *count)
{
	char	*tmp;
	char	*result;

	tmp = NULL;
	tmp = ft_substr(cmd, 0, (ft_strlen(cmd) - ft_strlen(next_arg(cmd))));
	result = remove_quotes(tmp);
	(*count)--;
	free(tmp);
	return (result);
}

static int	ft_get_outfile(char **tmp, t_cmd *command, t_list *env, int *count)
{
	char	*cmd;

	cmd = *tmp;
	command->redir_out.type = get_redir_type(cmd);
	while (ft_strchr("> \t", *cmd))
		cmd++;
	if (ft_get_redir_file(cmd, command, command->redir_out.type, \
		env) == -1)
	{
		ft_error(command->redir_out.file, strerror(errno));
		return (1);
	}
	*tmp = cmd;
	(*count)--;
	return (0);
}

static int	ft_get_infile(char **tmp, t_cmd *command, t_list *env, int *count)
{
	char	*cmd;

	cmd = *tmp;
	command->redir_in.type = get_redir_type(cmd);
	while (ft_strchr("< \t", *cmd))
		cmd++;
	if (ft_get_redir_file(cmd, command, command->redir_in.type, \
		env) == -1)
	{
		ft_error(command->redir_in.file, strerror(errno));
		return (1);
	}
	*tmp = cmd;
	(*count)--;
	return (0);
}

int	split_args(t_cmd *command, t_list *env)
{
	int		count;
	char	*cmd;
	int		index;

	index = 0;
	count = args_count(command->cmd);
	command->args = ft_calloc(count + 1, sizeof(char *));
	cmd = command->cmd;
	command->redir_in.type = NONE;
	command->redir_out.type = NONE;
	command->redir_in.file = NULL;
	command->redir_out.file = NULL;
	while (count)
	{
		while (cmd[0] && ft_strchr("\t ", cmd[0]))
			cmd++;
		if (ft_strchr(">", *cmd))
		{
			if (ft_get_outfile(&cmd, command, env, &count))
				return (1);
		}
		else if (ft_strchr("<", *cmd))
		{
			if (ft_get_infile(&cmd, command, env, &count))
				return (1);
		}
		else
		{
			command->args[index++] = ft_do_args(cmd, &count);
			next_arg(cmd);
		}
		cmd = next_arg(cmd);
	}
	return (0);
}
