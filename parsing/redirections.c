/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:17:38 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/16 19:49:30 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

enum e_redir
{
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
};

static char	*get_redir_files(char *str)
{
	char	*file;
	int	i;

	i = 0;
	while (str[i] && str[i] != '>' && str[i] != '<')
		i++;
	file = ft_substr(str, 0, i);
	return (file);
}

static int	get_redir_type(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && !ft_strchr("><", str[i]))
		i++;
	if (str[i] == '<' && str[i + 1] == '<') //symbol of heredoc
		return (HEREDOC);
	else if (str[i] == '>' && str[i + 1] == '>') //symbol of append
		return (APPEND);
	else if (str[i] == '>') //symbol redirection output
		return (REDIR_OUT);
	else if (str[i] == '<') //symbol redirection input
		return (REDIR_IN);
	return (-1);
}

char	**redirections(char *str, char **envp)
{
	char	**redir;
	char	*file;
	int	redir_type;
	int	i;

	i = 0;
	redir = malloc(sizeof(char *) * 4);
	while (i < 4)
		redir[i++] = NULL;
	i = 0;
	while (str && *str)
	{
		redir_type = get_redir_type(str);
		file = get_redir_files(str);
		if (redir_type == REDIR_IN)
			redir[0] = file;
		else if (redir_type == REDIR_OUT)
			redir[1] = file;
		else if (redir_type == APPEND)
			redir[2] = file;
		else if (redir_type == HEREDOC)
			redir[3] = file;
		str += ft_strlen(file);
		str += 2;
	}
	return (redir);
}

// int	main(int ac, char **av)
// {
// 	char	**redir;
// 	int	i;
//
// 	i = 0;
// 	redir = redirections(av[1], NULL);
// 	while (i < 4)
// 	{
// 		printf("file: %s\n", redir[i]);
// 		printf("type: %s\n", i == 0 ? "REDIR_IN" : i == 1 ? "REDIR_OUT" : i == 2 ? "APPEND" : "HEREDOC");
// 		i++;
// 		printf("*************\n");
// 	}
// 	return (0);
// }
