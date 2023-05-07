/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:20:34 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/07 23:24:17 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

typedef struct s_cmd
{
	char	*cmd; //whole command line !
	char	*exec; //executable name !
	char	**args; //arguments of the command !
	char	**redirection_files; //redirection files (input or output) !
	char	**redirection_type; //redirection type (input or output) !
	char	*delimiter; //delimiter (semicolon or pipe) !
	int	errors; //errors counter (syntax or semantic) !
	struct s_cmd	*next; //next command in the linked list !
}	t_cmd;
