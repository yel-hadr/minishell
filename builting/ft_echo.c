/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:19:21 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/17 13:14:32 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builting.h"

/*
	ft_echo: print the args
	@cmd: the cmd
	@envp: the envp
	return: 0 if success
*/

int ft_echo(t_cmd cmd)
{
	int flag;

	flag = 0;
	cmd.args++;
	if (ft_memcmp(*cmd.args, "-n", ft_strlen(*cmd.args)) == 0)
	{
		cmd.args++;
		flag = 1;
	}
	while (*cmd.args)
	{
		ft_putstr_fd(*cmd.args, STDOUT_FILENO);
		cmd.args++;
		if (*cmd.args)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (!flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
