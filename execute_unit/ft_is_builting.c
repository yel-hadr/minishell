/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:44:35 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/18 23:16:43 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"


int exec_builting(t_cmd *cmd, t_list **envp)
{
  if (!ft_strncmp(cmd->args[0], "echo", ft_strlen(cmd->args[0])))
    return (ft_echo(cmd->args));
  else if (!ft_strncmp(cmd->args[0], "cd", ft_strlen(cmd->args[0])))
    return (ft_cd(cmd->args, envp));
  else if (!ft_strncmp(cmd->args[0], "pwd", ft_strlen(cmd->args[0])))
    return (ft_pwd());
  else if (!ft_strncmp(cmd->args[0], "export", ft_strlen(cmd->args[0])))
    return (ft_export(cmd->args, envp));
  else if (!ft_strncmp(cmd->args[0], "exit", ft_strlen(cmd->args[0])))
    return (ft_exit(cmd->args));
}
int is_builting(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)))
		return (1);
	else if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
		return (1);
	else if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
		return (1);
	else if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
		return (1);
	else if (!ft_strncmp(cmd, "exit", ft_strlen(cmd)))
		return (1);
	return (0);
}
