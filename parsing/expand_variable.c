/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:52:20 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/07 03:09:19 by elakhfif         ###   ########.fr       */
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
	var = (char *)ft_calloc(sizeof(char) , (i - j + 1));
	while (j < i)
	{
		var[k] = str[j];
		k++;
		j++;
	}
	var[k] = '\0';
	return (var);
}

static char	*ft_strjoin_char(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_calloc(sizeof(char) , (ft_strlen(s1) + 2));
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

// static int	wexitstatus(int status)
// {
// 	static int	exit_status;
//
// 	if (status != -1)
// 		exit_status = status;
// 	return (exit_status);
// }

char		*expand_variable(char *str, t_list *env)
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
		if (str[i] == '$' && str[i + 1] && str[i + 1] != ' ' && str[i + 1] != '$'
			&& str[i + 1] != '\"' && str[i + 1] != '\'' && str[i + 1] != '\\'
			&& str[i + 1] != '\n')
		{
			 // if (str[i + 1] == '?')
			 // {
				// wexitstatus(ft_atoi(ft_getval("?", env)));
				// val = ft_itoa(wexitstatus(-1));
				// new_str = ft_strjoin(new_str, val);
				// free(val);
			 // }
			j = i + 1;
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
			new_str = ft_strjoin_char(new_str, str[i]);
			i++;
		}
	}
	free(str);
	return (new_str);
}
