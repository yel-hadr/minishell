/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:52:20 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/12 04:16:37 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_var(char *str, int i, int j)
{
	char	*var;
	int		k;

	k = 0;
	var = (char *)ft_calloc(sizeof(char), (i - j + 1));
	while (j < i)
	{
		var[k] = str[j];
		k++;
		j++;
	}
	var[k] = '\0';
	return (var);
}

static int	check_heredoc_var(char *str, int i, int *status)
{
	if (!str || !status)
		return (0);
	if (i && str[i] == '$')
		i--;
	while (i && ft_strchr(" \t", str[i]))
		i--;
	if (i > 0 && str[i] == '<' && str[i - 1] == '<')
		return (1);
	return (0);
}

static int	ft_expand_status(char **new_str, char chr, int *exit_status, int *i)
{
	char	*val;

	if (chr != '?')
		return (1);
	val = ft_itoa(*exit_status);
	*new_str = ft_strjoin_free(*new_str, val);
	free(val);
	*i += 2;
	return (0);
}

static int	ft_do_expand(char *str, char **new_str, int i, t_list *env)
{
	char	*var;
	char	*val;
	int		j;

	j = i + 1;
	i = next_var(str, i + 1);
	var = get_var(str, i, j);
	val = ft_getval(var, env);
	if (!val)
		val = strdup("");
	*new_str = ft_strjoin_free(*new_str, val);
	free(var);
	free(val);
	return (i);
}

char	*expand_variable(char *str, t_list *env, int *exit_status)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!str || !env || !ft_strchr(str, '$'))
		return (NULL);
	new_str = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$' && !ft_strchr("\t $\'\"'\n'", str[i + 1])
			&& !check_heredoc_var(str, i, exit_status))
		{
			if (!ft_expand_status(&new_str, str[i + 1], exit_status, &i))
				continue ;
			i = ft_do_expand(str, &new_str, i, env);
		}
		else
		{
			new_str = ft_strjoin_char(new_str, str[i]);
			i++;
		}
	}
	free(str);
	return (new_str);
}
