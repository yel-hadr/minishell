/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 03:49:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/09/09 09:48:45 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

void	ft_handler(int sig)
{
	int status;
	
	(void)sig;
	status = 0;
	wait(&status);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	
	if (status && WIFSIGNALED(status))
		g_exit_status = WTERMSIG(status) + 128;
	else
		rl_redisplay();
}