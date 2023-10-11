/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:15:48 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/10 03:30:02 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builting.h"

static int	ft_do_cd_home(char *oldpwd, t_list *env)
{
	char	*home;

	if (chdir(ft_getenv("HOME", env) + 5) == -1)
	{
		ft_error("cd", strerror(errno));
		free(oldpwd);
		return (1);
	}
	home = getcwd(NULL, 0);
	ft_setenv("OLDPWD", oldpwd, env);
	ft_setenv("PWD", home, env);
	free(home);
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

static int	ft_do_cd(char *args, char *oldpwd, t_list *env)
{
	char	*pwd;

	if (chdir(args) == -1)
	{
		ft_error("cd", strerror(errno));
		free(oldpwd);
		return (1);
	}
	pwd = getcwd(NULL, 0);
	ft_setenv("OLDPWD", oldpwd, env);
	ft_setenv("PWD", pwd, env);
	free(pwd);
	return (0);
}

int	ft_cd(char **args, t_list *env)
{
	char	*oldpwd;

	if (!args)
		return (1);
	oldpwd = getcwd(NULL, 0);
	if (!args[1] || !ft_strncmp(args[1], "~", 1))
	{
		if (ft_do_cd_home(oldpwd, env))
			return (1);
	}
	if (args[2])
	{
		ft_error("cd", "too many arguments");
		free(oldpwd);
		return (1);
	}
	else if (!ft_strncmp(args[1], "-", 1))
	{
		if (ft_cd_oldpwd(ft_getenv("OLDPWD", env) + 7, env))
			return (1);
	}
	else
		if (ft_do_cd(args[1], oldpwd, env))
			return (1);
	free(oldpwd);
	return (0);
}
