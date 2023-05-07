/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:57:46 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/07 23:18:44 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	print_error(char *delim)
{
	ft_putstr_fd("42sh: syntax error near unexpected token `", 3);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("'\n", 2);
}

char	*get_delim(char *line)
{
	int		i;
	char	delimite[2];

	i = 0;
	while (line[i] && line[i] != ';' && line[i] != '|')
		i++;
	delimite[0] = line[i];
	return (ft_strdup(delimite));
}

int	check_delim(char *line)
{
	int		i;
	char	*delimiter;

	i = 0;
	while (line[i])
	{
		if (line[i] == ';' || line[i] == '|')
		{
			delimiter = get_delim(line);
			if (strcmp(delimiter, ";") != 0
				&& strcmp(delimiter, "|") != 0)
			{
				print_error(delimiter);
				free(delimiter);
				return (0);
			}
			//free(delimiter);
			return (1);
		}
		i++;
	}
	return (0);
}
