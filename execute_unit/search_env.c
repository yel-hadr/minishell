/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:46:48 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/13 17:32:01 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

static char	*the_value(char *str)
{
	while (*str)
	{
		if (*str == '=')
			return (ft_strdup(str + 1));
		str++;
	}
	return (NULL);
}

char *search_env(char *variable, t_list *env)
{
	if (!variable)
		return (NULL);
	while (env)
	{
		if (!ft_strncmp(variable, env->content, ft_strlen(variable)) && ((char *)env->content)[ft_strlen(variable)] == '=')
			return (the_value((char *)env->content));
		env = env->next;
	}
	return (NULL);
}
