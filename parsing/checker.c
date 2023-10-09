/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:56:11 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/09 00:14:25 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	syntax_error(char *str)
{
	ft_putstr_fd("mish: syntax error near unexpected token `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("'\n", 2);
}

int	check_separator(t_cmd *cmd)
{
	char	*str;
	int		i;

	i = 0;
	str = cmd->cmd;
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|')
		{
			syntax_error("|");
			return (1);
		}
		else if (str[i] == '|')
		{
			i++;
			if (!(*str))
			{
				syntax_error("|");
				return (1);
			}
		}
		i++;
	}
	return (0);
}
