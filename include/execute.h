/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 04:15:24 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/10/08 04:59:49 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H

# define EXECUTE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include "../include/libft.h"
# include "parser.h"
# include "builting.h"

t_list	*ft_dupenvp(char **envp);
void	ft_restore_fd(int save_stdin, int save_stdout);
void	ft_handler(int sig);
void	ft_save_fd(int *save_stdin, int *save_stdout);
char	*is_cmd_exists(char **exe, t_list *envp);
char	*ft_getenv(char *var, t_list *envp_list);
char	**ft_lst_to_char(t_list *envp_list);
char	*ft_getval(char *var, t_list *envp);
int		ft_execute(t_cmd *cmd, t_list *envp);
int		ft_setenv(char *var, char *value, t_list *envp);
int		is_builting(char *cmd);
int		exec_builting(t_cmd *cmd, t_list *envp);
int		ft_redaraction(char *file, t_redir_type redaraction);
int		ft_pipe(t_cmd *cmd, t_list *envp);
int		ft_exec_the_cmd(t_cmd *cmd, t_list *envp);
int		execute(t_cmd *cmd, t_list *envp);

#endif
