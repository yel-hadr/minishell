/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:13:04 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/06 00:16:08 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

extern int g_sig;

typedef enum e_redir
{
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC,
	NONE,
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

typedef struct	s_cmd
{
	char	*cmd;
	char	**args;
	t_redir	redir_in;
	t_redir	redir_out;
	char  *sep;
	struct s_cmd	*next;
}				t_cmd;

//split_cmd is a function that split the input into commands and return a linked list of commands !
t_cmd			*split_cmd(char *input, int *status);
//add_cmd is a function that add a command to the linked list of commands !
t_cmd			*add_cmd(t_cmd *cmd, char *input);
//split_args is a function that split the command into arguments and return a table of arguments !
int				split_args(t_cmd *command, t_list *env);
//parser is a function that parse the input and return a linked list of commands !
t_cmd			*parser(char *line, t_list *env, int *status);
//check_separator is a function that check if the separator is valid or not !
int				check_separator(t_cmd *cmd);
//remove_quotes is a function that remove the quotes from the command and return the command without quotes !
char			*remove_quotes(char *cmd);
// get_redirections is a function that get the redirections from the command and return a table of redirections !
char			**get_redirections(char *input);
t_redir_type	get_redir_type(char *input);
int				ft_redir_open(char *file, t_redir_type type);
char			*expand_variable(char *str, t_list *env);
char			*ft_get_heredoc(char *heredoc, t_list *env);
int	check_redirections(t_cmd *cmd);

// char	*prompt(void);
char			*replace_all_words(char *str, char *w0, char *w1, int usefree);
char			*extract_branch(char *buff);
char			*get_host_name(void);
char			*get_branch_name(void);
char			*prompt_msg(void);

#endif
