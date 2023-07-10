#ifndef EXECUTE_H

#define EXECUTE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../parcing/parser.h"
#include "builting/builting.h"

char *is_cmd_exists(char **exe, char **envp);
int ft_execute(t_cmd *cmd, char **envp);
char *ft_getenv(char *var, t_list *envp_list);
int ft_setenv(char *var, char *value, t_list *envp);
char **ft_lst_to_char(t_list *envp_list);
t_list	*ft_dupenvp(char **envp);
int ft_error(char *cmd, char *error);
int is_builting(char *cmd);
int ft_redaraction(char *file, t_redir redaraction);
char *ft_strjoin_free(char *s1, char *s2);
int ft_pipe(t_cmd *cmd, t_list **envp);
#endif
