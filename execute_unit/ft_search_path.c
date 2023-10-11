/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:10:37 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/10 01:58:58 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

void	ft_free(char **ptr)
{
	char	**tmp;

	tmp = ptr;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(tmp);
}

char	*ft_getval(char *var, t_list *envp)
{
	char	*tmp;

	if (!var)
		return (NULL);
	tmp = ft_getenv(var, envp);
	if (tmp)
		return (strdup(tmp + ft_strlen(var) + 1));
	return (NULL);
}

static char	*ft_search_path(char **exe, char **path_split)
{
	char	*tmp;

	while (*path_split)
	{
		tmp = ft_strjoin(*path_split, "/");
		tmp = ft_strjoin_free(tmp, *exe);
		if (!access(tmp, F_OK))
		{
			if (!access(tmp, X_OK))
			{
				free(*exe);
				*exe = tmp;
				return (tmp);
			}
		}
		free(tmp);
		path_split++;
	}
	return (NULL);
}

static char	*ft_do_abspath(char **exe)
{
	DIR	*dir;

	dir = opendir(*exe);
	if (dir)
	{
		ft_error(*exe, "Is a directory");
		closedir(dir);
		exit(126);
	}
	if (!access(*exe, F_OK))
	{
		if (!access(*exe, X_OK))
			return (*exe);
		ft_error(*exe, strerror(errno));
		exit(126);
	}
	else
	{
		ft_error(*exe, strerror(errno));
		exit(127);
	}
	return (NULL);
}

char	*is_cmd_exists(char **exe, t_list *envp)
{
	char	*path;
	char	**path_split;

	if (!*exe || !exe)
		return (NULL);
	if (**exe == '/' || **exe == '.')
		return (ft_do_abspath(exe));
	path = ft_getval("PATH", envp);
	path_split = ft_split(path, ':');
	free(path);
	path = ft_search_path(exe, path_split);
	ft_free(path_split);
	return (path);
}
