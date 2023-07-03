/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:10:37 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/18 21:07:30 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

/*
	is_cmd_exists: check if the cmd exists in the path
	*exe: the cmd
	@envp: the envp
	@return: the path of the cmd if it exists, NULL otherwise
*/

void ft_free(char **ptr)
{
	char **tmp;

	tmp = ptr;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(tmp);
}

static char *ft_get_env(char *var, char **envp)
{
	int j;
	char *str;
	
	while (*envp)
	{
		j = 0;
		str = *envp;
		while (str[j] && str[j] != '=')
			j++;
		if (!ft_strncmp(str, var, j))
			return (str + j + 1);
		envp++;
	}
	return (NULL);
}

char *is_cmd_exists(char **exe, char **envp)
{
	char *path;
	char **path_split;
	char *tmp;
	char **ptr;

	if (!*exe || !exe)
		return (NULL);
	if (ft_strchr(*exe, '/') && !access(*exe, F_OK))
		return (*exe);
	path = ft_get_env("PATH", envp);
	if (!path)
		return (NULL);
	path_split = ft_split(path, ':');
	ptr = path_split;
	while (*path_split)
	{
		tmp = ft_strjoin(*path_split, "/");
		tmp = ft_strjoin(tmp,*exe);
		if (!access(tmp, F_OK))
		{
			ft_free(ptr);
			*exe = tmp;
			return (tmp);
		}
		free(tmp);
		path_split++;
	}
	ft_free(ptr);
	return (NULL);
}
