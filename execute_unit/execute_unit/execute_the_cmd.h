#ifndef EXECUTE_THE_CMD

#define EXECUTE_THE_CMD

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

typedef enum s_redir
{
	REDIR_INPUT,
	REDIR_OUTPUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	NONE
}	t_redir;

typedef struct s_redaraction
{
	t_redir redir;
	char *file;
}	t_redaraction;

typedef enum s_type
{
	PIPE,
	AND,
	OR,
	END
}	t_type;


typedef struct s_cmd
{
	char *cmd;
	char **args;
	t_redaraction redir_in;
	t_redaraction redir_out;
	t_type type;
}	t_cmd;

int ft_error(char *cmd, char *error);
int ft_execute(t_cmd cmd, char **envp);
int ft_redaraction(char *file, t_redir redaraction);

#endif