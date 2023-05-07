/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:57:46 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/06 21:07:18 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static void	print_error(char *delim)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("'\n", 2);
}

static char	*get_delim(char *line)
{
	int		i;
	char	*delimite;

	i = 0;
	while (line[i] && line[i] != ';' && line[i] != '|')
		i++;
	delimite = ft_substr(line, 0, i);
	return (delimite);
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
			free(delimiter);
			return (1);
		}
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%d\n", check_delim(av[1]));
	}
	return (0);
}
