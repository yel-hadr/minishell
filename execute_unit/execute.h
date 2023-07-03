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
#include "builting/builting.h"

typedef enum s_redir{
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	NONE
}	t_redir;

typedef struct s_redaraction{
	t_redir redir;
	char *file;
}	t_redaraction;

typedef enum s_type{
	PIPE,
	END
}	t_type;


typedef struct s_cmd{
	char *cmd;
	char **args;
	t_redaraction redir_in;
	t_redaraction redir_out;
	t_type separator;
}	t_cmd;

typedef struct s_execute{
	int pid;
	int fd[2];
	int fd_in;
	int herdoc_fd[2];
	int save_stdin;
	int save_stdout;
	t_cmd *cmd;
	t_list *tmp;
	int status;
}	t_execute;

int		ft_error(char *cmd, char *error);
int 	ft_execute(t_execute *cmd, char **envp);
int		ft_redaraction(char *file, t_redir redaraction);
int		ft_pipe(t_list *cmds, t_list **envp);
char	**ft_lst_to_char(t_list *envp_list);
char	*ft_getenv(char *var, t_list *envp_list);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_setenv(char *var, char *value, t_list *envp);
int 	is_builting(char *cmd);
t_list	*ft_dupenvp(char **envp);
int ft_herdoc(t_execute *cmd);
char *is_cmd_exists(char **exe, char **envp);
#endif
