/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 03:49:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/09/20 06:23:38 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

void	ft_handler(int sig)
{
    (void)sig;
    if (g_sig > 0)
        kill(0, SIGINT);
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	if (g_sig == -1)
		close(STDIN_FILENO);
    else if (g_sig >= 1)
        rl_redisplay();
    g_sig = 0;
}
