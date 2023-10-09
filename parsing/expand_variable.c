/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:52:20 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/09 00:58:14 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	next_var(char *str, int i)
{
	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '\"'
		&& str[i] != '\'' && str[i] != '\\' && str[i] != '\n')
		i++;
	return (i);
}

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

// static char	*skip_var(char *str, int i)
// {
// 	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '\"'
// 		&& str[i] != '\'' && str[i] != '\\' && str[i] != '\n')
// 		i++;
// 	return (str + i);
// }

static char	*ft_strjoin_char(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + 2));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[++i] = '\0';
	free(s1);
	return (str);
}

int	check_herdoc_var(char *str, int i, int *status)
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

char	*expand_variable(char *str, t_list *env, int *exit_status)
{
	int		i;
	int		j;
	char	*var;
	char	*new_str;
	char	*val;

	i = 0;
	j = 0;
	if (!str || !env || !ft_strchr(str, '$'))
		return (NULL);
	new_str = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] != ' ' && str[i
			+ 1] != '$' && str[i + 1] != '\"' && str[i + 1] != '\'' && str[i
			+ 1] != '\\' && str[i + 1] != '\n' && !check_herdoc_var(str, i,
			exit_status))
		{
			j = i + 1;
			if (str[i + 1] == '?')
			{
				val = ft_itoa(*exit_status);
				new_str = ft_strjoin(new_str, val);
				free(val);
				i += 2;
				continue ;
			}
			i = next_var(str, i + 1);
			var = get_var(str, i, j);
			val = ft_getval(var, env);
			if (!val)
				val = strdup("");
			new_str = ft_strjoin(new_str, val);
			free(val);
			free(var);
		}
		else
		{
			new_str = ft_strjoin_char(new_str, str[i + 1]);
			i += 2;
		}
	}
	free(str);
	return (new_str);
}
