/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/16 20:17:59 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*next_arg(char *cmd)
{
	int	i;

	i = 0;
	while (cmd && !ft_strchr(" \t><", cmd[i]))
	{
		if (ft_strchr("\"\'", cmd[i]))
		{
			skip_quotes(cmd, i);
			i = quote_len(cmd, i);
		}
		i++;
	}
	return (cmd + i);
}

static int	is_redir(char *arg)
{
	if (ft_strchr("><", arg[0]))
	{
		while (arg && ft_strchr(" \t", *arg))
			arg++;
		if (arg && ft_strchr("><", *arg))
			return (1);
	}
	return (0);
}

int	counter(char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd && cmd[i])
	{
		while (cmd[i] && ft_strchr(" \t", cmd[i]))
			i++;
		if (cmd[i] && !ft_strchr("><", cmd[i]))
		{
			count++;
			i += next_arg(cmd + i) - cmd - i;
		}
		else
			i++;
	}
	return (count + 1);
}

char	**split_args(char *cmd)
{
	char	**args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	args = ft_calloc(counter(cmd), sizeof(char *));
	while (cmd && cmd[i])
	{
		while (cmd[i] && ft_strchr(" \t", cmd[i]))
			i++;
		if (cmd[i] && !ft_strchr("><", cmd[i]))
		{
			args[j] = ft_substr(cmd, i, next_arg(cmd + i) - cmd - i);
			i += next_arg(cmd + i) - cmd - i;
			j++;
		}
		else if (cmd[i] && is_redir(cmd + i))
		{
			args[j] = ft_substr(cmd, i, 1);
			i++;
			j++;
		}
	}
	args[j] = NULL;
	return (args);
}

int	main(int ac, char **av)
{
	char	**args;
	int		i;

	i = 0;
	args = split_args(av[1]);
	while (args[i])
	{
		printf("args[%i]:\t'%s'\n", i, args[i]);
		printf("redir:\t[%i]\n", is_redir(args[i]));
		i++;
	}
	return (0);
}
