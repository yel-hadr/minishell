/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:43:33 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/13 04:57:55 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*ft_check_error(t_list *env)
{
	char	*input;
	char	*result;

	input = NULL;
	result = NULL;
	if (!env || !env->content)
	{
		ft_putstr_fd("minishell: fatal error: ", 2);
		exit(1);
	}
	input = readline(GRN "minishell > " RESET);
	if (!input)
	{
		printf("exit\n");
		exit(0);
	}
	add_history(input);
	result = ft_strtrim(input, " \t");
	if (input)
		free(input);
	return (result);
}

void	ft_free_cmds(t_cmd *cmds)
{
	t_cmd	*tmp;

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

int		g_sig;

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmds;
	t_list	*env;
	int		status;
	int		fd[2];

	(void)argc;
	(void)argv;
	status = 0;
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, SIG_IGN);
	env = ft_dupenvp(envp);
	while (1)
	{
		g_sig = 0;
		ft_save_fd(&fd[0], &fd[1]);
		cmds = parser(ft_check_error(env), env, &status);
		if (!status && !g_sig)
			status = ft_pipe(cmds, env);
		ft_restore_fd(fd[0], fd[1]);
		if (cmds)
			ft_free_cmds(cmds);
	}
	ft_lstclear(&env, free);
	return (0);
}
