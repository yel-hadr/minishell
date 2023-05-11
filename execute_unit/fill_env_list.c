/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:17:44 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/11 18:45:40 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

t_list *ft_creat_env(char **env)
{
	int i = 0;
	char *str; 
	t_list *head;
	
	while (env[i])
	{
		str = ft_calloc(sizeof(char), ft_strlen(env[i]) + 1);
		if (!str)
			return (NULL);
		ft_memmove(str, env[i],ft_strlen(env[i]));
		ft_lstadd_back(&head, ft_lstnew((void *)str));
		i++;
	}
	return (head);
}