/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:13:04 by elakhfif          #+#    #+#             */
/*   Updated: 2023/07/08 14:22:21 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_redir
{
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC,
	NONE
} t_redir_type;

typedef enum e_sep
{
  PIPE,
  END,
} t_sep;

typedef struct s_redir
{
  char			*file;
  t_redir_type	type;
}	t_redir;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct	s_cmd
{
	char	*cmd;
	char	**args;
  t_redir	redir_in;
  t_redir	redir_out;
  char  *sep;
	int	error;
	//pid_t	process_id;
	struct s_cmd	*next;
}				t_cmd;

//split_cmd is a function that split the input into commands and return a linked list of commands !
t_cmd	*split_cmd(char *input);
//add_cmd is a function that add a command to the linked list of commands !
t_cmd	*add_cmd(t_cmd *cmd, char *input);
//split_args is a function that split the command into arguments and return a table of arguments !
char	**split_args(char *cmd);
//parser is a function that parse the input and return a linked list of commands !
t_cmd	*parser(char *line);
//check_separator is a function that check if the separator is valid or not !
int	check_separator(t_cmd *cmd);
//remove_quotes is a function that remove the quotes from the command and return the command without quotes !
char	*remove_quotes(char *cmd);
// get_redirections is a function that get the redirections from the command and return a table of redirections !
char	**get_redirections(char *input);

#endif
