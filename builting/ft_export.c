/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:23:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/09/23 23:38:38 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builting.h"

static int	ft_print_export(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		if (ft_strchr(tmp->content, '='))
		{
			write(1, tmp->content, ft_strchr(tmp->content, '=') \
				- (char *)tmp->content + 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(ft_strchr(tmp->content, '=') + 1, 1);
			ft_putstr_fd("\"", 1);
		}
		else
			ft_putstr_fd(tmp->content, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
	return (0);
}

static int	check_var(char *var)
{
	if (!var)
		return (1);
	if (!ft_isalpha(*var) && *var != '_')
		return (1);
	while (*var && *var != '=')
	{
		if (!ft_isalnum(*var) && *var != '_')
			return (1);
		var++;
	}
	return (0);
}

static int	ft_set_export(char *args, t_list *env)
{
	char	*var;
	char	*value;

	var = ft_substr(args, 0, ft_strchr(args, '=') - args);
	value = ft_substr(args, ft_strchr(args, '=') \
			- args + 1, ft_strlen(args));
	ft_setenv(var, value, env);
	free(var);
	free(value);
	return (0);
}

int	ft_export(char **args, t_list *env)
{
	int		i;

	i = 1;
	if (!args[1])
		return (ft_print_export(env));
	while (args[i])
	{
		if (check_var(args[i]))
		{
			ft_error("export", "not a valid identifier");
			return (1);
		}
		if (ft_strchr(args[i], '='))
			ft_set_export(args[i], env);
		else
			ft_setenv(args[i], NULL, env);
		i++;
	}
	return (0);
}
