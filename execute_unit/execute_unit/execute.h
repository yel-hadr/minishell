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
#include <string.h>
#include <fcntl.h>
#include "../libft/libft.h"

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

int		ft_error(char *cmd, char *error);
int		ft_execute(t_cmd cmd, char **envp);
int		ft_redaraction(char *file, t_redir redaraction);
int		ft_pipe(t_list *cmds, char **envp);
char	**ft_lst_to_char(t_list *envp_list);
char	*ft_getenv(char *var, t_list *envp_list);
t_list	*ft_dupenvp(char **envp);

#endif
