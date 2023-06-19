/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:19:21 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/18 21:28:13 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builting.h"

/*
	ft_echo: print the args
	@cmd: the cmd
	@envp: the envp
	return: 0 if success
*/

int ft_echo(char **args)
{
	int flag;

	flag = 0;
	args++;
	if (ft_memcmp(*args, "-n", ft_strlen(*args)) == 0)
	{
		args++;
		flag = 1;
	}
	while (*args)
	{
		ft_putstr_fd(*args, STDOUT_FILENO);
		args++;
		if (*args)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (!flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
