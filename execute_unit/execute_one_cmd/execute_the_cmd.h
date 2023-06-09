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
#include "../libft/libft.h"

typedef enum t_redaration
{
	REDARATION_INPUT,
	REDARATION_OUTPUT,
	REDARATION_APPEND,
	REDARATION_HEREDOC,
	NONE
}	t_redaration;

typedef enum t_type
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
	t_redaration redaration;
	char *file;
	t_type type;
}	t_cmd;

int execute_the_cmd(char **cmd, char **envp);


#endif