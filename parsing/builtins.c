/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 08:36:47 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/15 08:40:27 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	builtins(char *cmd)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(cmd);
	if (len == 2 && !ft_strncmp(cmd, "cd", 2))
		return (1);
	else if (len == 3 && !ft_strncmp(cmd, "pwd", 3))
		return (1);
	else if (len == 4 && !ft_strncmp(cmd, "echo", 4))
		return (1);
	else if (len == 5 && !ft_strncmp(cmd, "unset", 5))
		return (1);
	else if (len == 6 && !ft_strncmp(cmd, "export", 6))
		return (1);
	else if (len == 4 && !ft_strncmp(cmd, "exit", 4))
		return (1);
	return (0);
}
