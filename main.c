/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:43:33 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/12 16:58:45 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	ft_check_input(char *input)
{
	while (*input)
	{
		if (*input != ' ' && *input != '\t')
			return (1);
		input++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_cmd	*cmds;
	char	*input;
	t_list *env;
	g_exit_status = 0;
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, SIG_IGN);
	env = ft_dupenvp(envp);
  	while (1)
	{
		if (!env || !env->content)
		{
			printf("minishell: fatal error: env is empty\n");
			exit(1);
		}
		input = readline("minishell > ");
		if (!input)
		{
			printf("exit\n");
			exit(0);
		}
		else if (ft_check_input(input))
		{
			add_history(input);
			cmds = parser(input);
			ft_pipe(cmds, env);
		}
		free(input);
	}

	return (0);
}
