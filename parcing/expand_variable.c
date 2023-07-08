/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:52:20 by elakhfif          #+#    #+#             */
/*   Updated: 2023/07/03 19:34:27 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	var = (char *)malloc(sizeof(char) * (i - j + 1));
	while (j < i)
	{
		var[k] = str[j];
		k++;
		j++;
	}
	var[k] = '\0';
	return (var);
}

static char	*skip_var(char *str, int i)
{
	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '\"'
		&& str[i] != '\'' && str[i] != '\\' && str[i] != '\n')
		i++;
	return (str + i);
}

static char	*get_var_value(char *var, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, var) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

static char	*ft_strjoin_char(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
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

char		*expand_variable(char *str, t_env *env)
{
	int		i;
	int		j;
	char	*var;
	char	*var_value;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] != ' '
			&& str[i + 1] != '\"' && str[i + 1] != '\''
			&& str[i + 1] != '\\' && str[i + 1] != '\n')
		{
			j = i + 1;
			i = next_var(str, i + 1);
			var = get_var(str, i, j);
			var_value = get_var_value(var, env);
			new_str = ft_strjoin(new_str, var_value);
			free(var);
		}
		else
			new_str = ft_strjoin_char(new_str, str[i]);
		i++;
	}
	return (new_str);
}

int	main(void)
{
	char	*str;
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->key = ft_strdup("HOME");
	env->value = ft_strdup("/Users/elakhfif");
	env->next = NULL;
	str = ft_strdup("hello $HOME");
	printf("%s\n", expand_variable(str, env));
	return (0);
}
