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

int	main(int argc, char **argv, char **envp)
{
  (void)argc;
  (void)argv;
	t_cmd	*cmds;
  char	*input;

  	while (1)
	{
    input = readline("minishell > ");
		add_history(input);
		cmds = parser(input);
    free(input);
    t_list *env = ft_dupenvp(envp);
    ft_pipe(cmds, &env);
    
	}

	return (0);
}
