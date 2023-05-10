/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_unit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:12:30 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/10 13:15:55 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_UNIT_H
#define EXECUTE_UNIT_H

#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"

typedef struct s_cmd
{
	char	*cmd;					//whole command line !
	char	*exec;					//executable name !
	char	**args;					//arguments of the command !
	char	**redirection_files;	//redirection files (input or output) !
	char	**redirection_type;		//redirection type (input or output) !
	char	*delimiter;				//delimiter (semicolon or pipe) !
	int		errors;					//errors counter (syntax or semantic) !
	struct s_cmd	*next;			//next command in the linked list !
}	t_cmd;

typedef struct s_env
{
	char *name;
	char *value;
	struct s_env	*next;
}	t_env;

#endif