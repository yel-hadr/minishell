/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:23:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/18 21:15:00 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builting.h"

static int	ft_print_export(t_list *env)
{
	t_list *tmp;

	tmp = env;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp->content, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	return (0);
}

static int	check_var(char *var)
{
	while (*var)
	{
		if (!ft_isalnum(*var) && *var != '_')
			return (1);
		var++;
	}
	return (0);
}


int    ft_export(char **args, t_list **env)
{
	int i;
	char *var;
	char *value;

	i = 1;
	if (!args[1])
		return (ft_print_export(*env));
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			var = ft_substr(args[i], 0, ft_strchr(args[i], '=') - args[i]);
			if (check_var(var))
			{
				ft_error("export", "not a valid identifier");
				return (1);
			}
			value = ft_strchr(args[i], '=') + 1;
			ft_setenv(var, value, *env);
		}
		
		i++;
	}
	return (0);
}

