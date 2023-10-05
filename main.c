/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:43:33 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/05 15:09:00 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

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

char *ft_prompt(t_list *env)
{
	char *user;
	char *dir;
	char *tmp;
	char *result;
	
	user = NULL;
	dir = NULL;
	result = NULL;

	user = ft_getval("USER", env);
	tmp = getcwd(NULL, 0);
	dir = ft_strrchr(tmp, '/');
	if (!dir)
		dir = tmp;
	else
		dir++;
	if (!user || !dir)
		result = ft_strdup(GRN"minishell > "RESET);
	else
	{
		result = ft_strjoin(GRN, user);
		result = ft_strjoin(result, RESET);
		result = ft_strjoin(result, " : ");
		result = ft_strjoin(result, BLU);
		result = ft_strjoin(result, dir);
		result = ft_strjoin(result, RESET);
		result = ft_strjoin(result, " > ");
	}
	if (user)
		free(user);
	if (tmp)
		free(tmp);
	return (result);
} 

char *ft_check_error(t_list *env)
{
	char *input;
	char *result;
	char *prompt;
	
	input = NULL;
	result = NULL;
	if (!env || !env->content)
	{
		ft_putstr_fd("minishell: fatal error: ", 2);
		exit(1);
	}
	prompt = ft_prompt(env);
	input = readline(prompt);
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

int g_sig;

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

  	while (1)
	{
		g_sig = 0;
		ft_save_fd(&save_stdin, &save_stdout);
		input = ft_check_error(env);
		cmds = parser(input, env, &status);
		status = ft_pipe(cmds, env);
		if (input)
			free(input);
		if (cmds)
			ft_free_cmds(cmds);
		ft_restore_fd(save_stdin, save_stdout);
	}

	return (0);
}
