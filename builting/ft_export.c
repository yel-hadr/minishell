/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:23:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/17 15:30:45 by yel-hadr         ###   ########.fr       */
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

int    ft_export(char **args, t_list *env)
{
	int i;
	char *tmp;
	char *tmp2;

	i = 1;
	if (!args[1])
		return (ft_print_export(env));
	while (args[i])
	{
		if (ft_strchr(args[i], '='))
		{
			tmp = ft_substr(args[i], 0, ft_strchr(args[i], '=') - args[i]);
			if (check_var(tmp) == 1)
			{
				ft_putstr_fd("bash: export: `", 2);
				ft_putstr_fd(tmp, 2);
				ft_putstr_fd("': not a valid identifier\n", 2);
				free(tmp);
				return (1);
			}
			tmp2 = ft_substr(args[i], ft_strchr(args[i], '=') - args[i] + 1, ft_strlen(args[i]));
			ft_setenv(tmp, tmp2, env);
			free(tmp);
			free(tmp2);
		}
		else
			ft_setenv(args[i], "", env);
		i++;
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
	t_list *list;
	list = ft_dupenvp(env);
	ft_export(av, list);
	// ft_print_export(list);
	return (0);
}