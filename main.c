/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:43:33 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/23 06:40:02 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parcing/parser.h"
#include "execute_unit/execute.h"

static t_list *ft_depenvp(char **envp)
{
  t_list *env;
  int i;

  i = 0;
  env = NULL;
  while (envp[i])
  {
    ft_lstadd_back(&env, ft_lstnew(ft_strdup(envp[i])));
    i++;
  }
  return (env);
}

int	main(int argc, char **argv, char **envp)
{
  (void)argc;
  (void)argv;
	t_cmd	*cmds;
  	char	*input;

  	while (1)
	{
    input = readline("minishell$ ");
		add_history(input);
		cmds = parser(input);
    t_list *env = ft_depenvp(envp);
    ft_pipe(cmds, &env);
		cmds = cmds->next;
	}
	return (0);
}
