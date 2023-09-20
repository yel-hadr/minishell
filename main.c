/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:43:33 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/20 03:16:02 by yel-hadr         ###   ########.fr       */
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

void ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void ft_free_cmds(t_cmd *cmds)
{
	t_cmd *tmp;

	while (cmds)
	{
		tmp = cmds->next;
		if (cmds->cmd)
			free(cmds->cmd);
		if (cmds->args)
			ft_free_array(cmds->args);
		if (cmds->redir_in.file)
			free(cmds->redir_in.file);
		if (cmds->redir_out.file)
			free(cmds->redir_out.file);
		free(cmds);
		cmds = tmp;
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_cmd	*cmds;
	char	*input;
	t_list *env;
	int status=0;
	int save_stdin;
	int save_stdout;

	signal(SIGINT, ft_handler);
	signal(SIGQUIT, SIG_IGN);
	env = ft_dupenvp(envp);
	g_sig = 0;
	
  	while (1)
	{
		ft_save_fd(&save_stdin, &save_stdout);
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
			cmds = parser(input, env, &status);
			status = ft_pipe(cmds, env);
		}
		if (input)
			free(input);
		// if (cmds)
		// 	ft_free_cmds(cmds);
		ft_restore_fd(save_stdin, save_stdout);
	}

	return (0);
}
