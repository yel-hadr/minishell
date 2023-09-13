/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:10:37 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/09/13 07:38:55 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

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

char *ft_getval(char *var, t_list *envp)
{
	char *tmp;
	
	if (!var)
		return (NULL);
	tmp = ft_getenv(var, envp);
	if (tmp)
		return (strdup(tmp + ft_strlen(var) + 1));
	return (NULL);
}

char *is_cmd_exists(char **exe, t_list *envp)
{
	char *path;
	char **path_split;
	char *tmp;
	char **ptr;

	if (!*exe || !exe)
		return (NULL);
	if (**exe == '/' || **exe == '.')
  {
    if (!access(*exe, F_OK))
      return (*exe);
    return (NULL);
  }
	path = ft_getval("PATH", envp);
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
