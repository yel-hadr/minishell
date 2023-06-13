/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_the_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:34:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/13 19:39:51 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_the_cmd.h"



int ft_execute(t_cmd cmd, char **envp)
{
	if (cmd.redir_in.file)
		ft_redaraction(cmd.redir_in.file, cmd.redir_in.redir);
	if (cmd.redir_out.file)
		ft_redaraction(cmd.redir_out.file, cmd.redir_out.redir);
	if (cmd.args[0])
		execve(cmd.args[0], cmd.args, envp);
	return (1);
}

