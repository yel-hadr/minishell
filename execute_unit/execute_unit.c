/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:54:26 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/15 17:05:44 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

static char	*ft_join_to_path(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 2, sizeof(char));
	if (!p)
		return (NULL);
	ft_memmove(p, s1, ft_strlen(s1));
	p[ft_strlen(s1)] = '/';
	ft_memmove(p + ft_strlen(s1)+1, s2, ft_strlen(s2));
	return (p);
}

char *search_for_cmd(char *str, char **path)
{
	while (*path)
	{
		*path = ft_join_to_path(*path, str);
		printf ("%s\n", *path);
		path++;
	}
	return (NULL);
}

// int ft_execute_cmd(t_cmd *cmd, t_list *env)
// {
// 	(void)cmd;
// 	char *path;
// 	path = search_for_cmd(cmd, ft_split(search_env(PATH, env), ':'));
// 	return (0);
// }

int execute_unit(t_list *env, t_cmd *cmd)
{
	(void)env;
	int e_status;
	t_cmd *curr;

	e_status = 0;
	curr = cmd;
	while (cmd)
	{
		
		cmd = cmd->next;
	}
	return (e_status);
}

int main (int ac, char *av[], char *aenv[])
{
	(void)av;
	(void)ac;
	t_list *env;

	env = ft_creat_env(aenv);
	char **str = ft_split(search_env(PATH, env), ':');
	char *ptr = ft_strdup("ls");
	search_for_cmd(ptr, str);
}
