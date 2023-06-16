/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:56:11 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/16 19:49:45 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*next_redir(char *str)
{
	while (*str && *str != '>' && *str != '<')
		str++;
	return (str);
}

static int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(" \t", str[i]))
		i++;
	return (i);
}

static char	*extract_redir(char *str)
{
	int		i;
	int		j;
	char	*redir;

	i = 0;
	j = 0;
	while (str[i] && ft_strchr("><", str[i]))
		i++;
	while (str[i] && ft_strchr(" \t", str[i]))
		i++;
	while (str[i + j] && !ft_strchr(" \t><", str[i + j]))
		j++;
	redir = ft_substr(str, i, j);
	return (redir);
}

static int	redir_count(char *cmd)
{
	int	i;
	int	count;

	cmd = next_redir(cmd);
	i = 0;
	count = 0;
	while (cmd[i])
	{
		count++;
		if (ft_strchr("><", cmd[i]))
		{
			while (cmd[i] && ft_strchr("><", cmd[i]))
				i++;
			while (cmd[i] && ft_strchr(" \t", cmd[i]))
				i++;
			if (cmd[i] == '\0')
				return (count);
		}
		i++;
		cmd = next_redir(cmd + i);
	}
	return (count);
}

char	**get_redir(char *cmd)
{
	int		i;
	int		j;
	int		count;
	char	**redir;

	i = 0;
	j = 0;
	count = redir_count(cmd);
	redir = (char **)malloc(sizeof(char *) * (count + 1));
	while (cmd[i])
	{
		if (ft_strchr("><", cmd[i]))
		{
			redir[j] = extract_redir(cmd + i);
			j++;
			while (cmd[i] && ft_strchr("><", cmd[i]))
				i++;
			while (cmd[i] && ft_strchr(" \t", cmd[i]))
				i++;
			if (cmd[i] == '\0')
				break ;
		}
		i++;
	}
	redir[j] = NULL;
	return (redir);
}

//the objectif of this file is to check if the redirections are well parsed and extracted from the command line
// int main()
// {
// 	char *cmd = "ls -l > file2 < file1 >> file3";
// 	char **redir = get_redir(cmd);
// 	int i = 0;
// 	while (redir[i])
// 	{
// 		printf("%s\n", redir[i]);
// 		i++;
// 	}
// 	return (0);
// }
