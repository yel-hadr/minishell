/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:46:48 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/11 20:19:58 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

char *search_env(char *variable, t_list *env)
{
	if (!variable)
		return (NULL);
	while (env)
	{
		if (!ft_strncmp(variable, env->content, ft_strlen(variable)) && ((char *)env->content)[ft_strlen(variable)] == '=')
			return ((char *)env->content);
		env = env->next;
	}
	return (NULL);
}
