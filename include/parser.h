/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:13:04 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/13 06:01:55 by yel-hadr         ###   ########.fr       */
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

extern int	g_sig;

typedef enum e_redir
{
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC,
	ERROR,
	NONE,
}	t_redir_type;

typedef struct s_redir
{
	char			*file;
	t_redir_type	type;
}	t_redir;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	t_redir			redir_in;
	t_redir			redir_out;
	char			*sep;
	struct s_cmd	*next;
}				t_cmd;

t_redir_type	get_redir_type(char *input);
t_cmd			*split_cmd(char *input, int *status);
t_cmd			*add_cmd(t_cmd *cmd, char *input);
t_cmd			*add_cmd_back(t_cmd **cmd, t_cmd *new);
t_cmd			*new_cmd(char *cmd);
t_cmd			*free_cmd(t_cmd *cmd);
t_cmd			*parser(char *line, t_list *env, int *status);
char			*remove_quotes(char *cmd);
char			**get_redirections(char *input);
char			*expand_variable(char *str, t_list *env, int *exit_status);
char			*ft_get_heredoc(char *heredoc, t_list *env);
char			*replace_all_words(char *str, char *w0, char *w1, int usefree);
char			*extract_branch(char *buff);
char			*get_host_name(void);
char			*get_branch_name(void);
char			*prompt_msg(void);
int				split_args(t_cmd *command, t_list *env);
int				check_separator(t_cmd *cmd);
int				ft_redir_open(char *file, t_redir_type type);
int				check_redirections(t_cmd *cmd);
char			**ms_wildcard(char *wildcard);
char			*next_arg(char *cmd);
int				args_count(char *cmd);
int				ft_get_redir_file(char *input, t_cmd *cmd, t_redir_type type, \
					t_list *env);
int				skip_wspace(char *input, int i);

#endif
