/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:37:10 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/16 19:55:17 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*line;
	char	**cmd;
	int		i;

	i = 0;
	while (1)
	{
		line = readline("21sh$\t> ");
		if (!line)
			break ;
		cmd = split_args(line);
		add_history(line);
		while (cmd[i])
		{
			printf("args[%d] = %s\n", i, cmd[i]);
			i++;
		}
		i = 0;
		free(line);
		free(cmd);
	}
	return (0);
}
