/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:48 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/09/23 23:38:55 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builting.h"

static int	ft_do_cd_home(char *oldpwd, t_list *env)
{
	if (chdir(ft_getenv("HOME", env) + 5) == -1)
	{
		ft_error("cd", strerror(errno));
		return (1);
	}
	ft_setenv("OLDPWD", oldpwd, env);
	ft_setenv("PWD", getcwd(NULL, 0), env);
	return (0);
}

static int	ft_cd_oldpwd(char *oldpwd, t_list *env)
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
	return (0);
}

int	ft_cd(char **args, t_list *env)
{
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (!args[1] || !ft_strncmp(args[1], "~", 1))
	{
		if (ft_do_cd_home(oldpwd, env))
			return (1);
	}
	else if (!ft_strncmp(args[1], "-", 1))
	{
		if (ft_cd_oldpwd(ft_getenv("OLDPWD", env) + 7, env))
			return (1);
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
