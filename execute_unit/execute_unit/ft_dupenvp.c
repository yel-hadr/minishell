/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupenvp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:47:33 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/15 09:59:24 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

char *ft_getenv(char *var, t_list *envp_list)
{
	while (envp_list)
	{
		if (!ft_strncmp(envp_list->content, var, ft_strlen(var)))
			return (envp_list->content);
		envp_list = envp_list->next;
	}
	return (NULL);
}

char **ft_lst_to_char(t_list *envp_list)
{
	char	**envp;
	int		i;

	i = 0;
	envp = ft_calloc(sizeof(char *) ,(ft_lstsize(envp_list) + 1));
	while (envp_list)
	{
		envp[i] = ft_strdup(envp_list->content);
		envp_list = envp_list->next;
		i++;
	}
	return (envp);
}

t_list	*ft_dupenvp(char **envp)
{
	t_list	*envp_list;
	t_list	*tmp;

	envp_list = NULL;
	while (*envp)
	{
		tmp = ft_lstnew(ft_strdup(*envp));
		ft_lstadd_back(&envp_list, tmp);
		envp++;
	}
	return (envp_list);
}
