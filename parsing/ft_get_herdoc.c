/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_herdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:21:35 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/09 15:52:41 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	ft_check_expand(char *str)
{
	if (!str)
		return (0);
	if (!ft_strchr(str, '$'))
		return (0);
	while (*str)
	{
		if (ft_strchr("\'\"", *str))
			return (1);
		str++;
	}
	return (0);
}

static char	*ft_remove_quotes(char *str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	if (!ft_strchr(str, '\'') && !ft_strchr(str, '\"'))
		return (str);
	tmp = remove_quotes(str);
	free(str);
	return (tmp);
}

char	*ft_get_heredoc(char *heredoc, t_list *env)
{
	char	*tmp;
	char	*line;
	int		expand;

	if (!heredoc || g_sig == -2)
		return (NULL);
	expand = 1;
	tmp = NULL;
	line = NULL;
	if (ft_check_expand(heredoc))
		expand = 0;
	heredoc = ft_remove_quotes(heredoc);
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, heredoc) || !line || g_sig == -2)
		{
			free(line);
			break ;
		}
		if (expand && ft_strchr(line, '$'))
			line = expand_variable(line, env, NULL);
		tmp = ft_strjoin_free(tmp, line);
		tmp = ft_strjoin_free(tmp, "\n");
		if (line)
			free(line);
	}
	return (tmp);
}
