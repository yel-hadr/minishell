/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:43:33 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/09 09:29:48 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"


int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_cmd	*cmds;
	char	*input;
	t_list *env = ft_dupenvp(envp);
	g_exit_status = 0;
	
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, SIG_IGN);
	
  	while (1)
	{
		input = readline("minishell > ");
		add_history(input);
		cmds = parser(input);
		free(input);
		ft_pipe(cmds, env);
	}

	return (0);
}
