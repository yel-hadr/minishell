/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 03:49:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/09 00:26:55 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/execute.h"

// void	ft_handler(int sig)
// {
// 	(void)sig;
// 	if (g_sig > 0)
// 	{
// 		kill(0, SIGINT);
// 		g_sig = 0;
// 	}
// 	printf("\n");
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	if (g_sig == -1)
// 	{
// 		close(STDIN_FILENO);
// 		g_sig = -2;
// 	}
// 	else if (g_sig >= 0)
// 		rl_redisplay();
// }

void    ft_handler(int sig)
{
    (void)sig;
    if (g_sig > 0)
    {
        rl_on_new_line();
        rl_replace_line("", 0);
    }
    else
    {
		if (g_sig == -1)
		{
			close(STDIN_FILENO);
			g_sig = -2;
		}
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}
