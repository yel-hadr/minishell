/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:54:26 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/10 13:30:12 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

t_cmd	*ft_pipe(t_cmd cmd)
{
	int file;
	file = open("output.txt", O_RDWR | O_CREAT, 777);
	
	while (!ft_strncmp(cmd.delimiter, "|", ft_strlen(cmd.delimiter)))
	{
		
	}
}

int execute_unit(t_cmd *cmd, t_env env)
{
	t_cmd *head;
	head = cmd;
	while (cmd)
	{
		if (cmd->delimiter == '|')
		{		
		}
	}
}