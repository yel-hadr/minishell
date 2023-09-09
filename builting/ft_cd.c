/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:48 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/09/07 06:28:18 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builting.h"

/*
	ft_cd: change the current directory
	@cmd: the cmd
	@env: the env
	return: 0 if success
*/



int ft_cd(char  **args, t_list *env)
{
	char *oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (!args[1])
	{
		if (chdir(ft_getenv("HOME", env) + 5) == -1)
		{
			ft_error("cd", strerror(errno));
			return (1);
		}
		ft_setenv("OLDPWD", oldpwd, env);
		ft_setenv("PWD", getcwd(NULL, 0), env);
	}
	else if (!ft_strncmp(args[1], "-", 1))
	{
		if (!oldpwd)
		{
			ft_error("cd", "OLDPWD not set");
			return (1);
		}
		else if (chdir(oldpwd) == -1)
		{
			ft_error("cd", strerror(errno));
			return (1);
		}
		ft_setenv("OLDPWD", oldpwd, env);
		ft_setenv("PWD", oldpwd, env);
	}
	else
	{
		if (chdir(args[1]) == -1)
		{
			ft_error("cd", strerror(errno));
			return (1);
		}
		ft_setenv("OLDPWD", oldpwd, env);
		ft_setenv("PWD", getcwd(NULL, 0), env);
	}
	return (0);
}