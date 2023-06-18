/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:11:48 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/18 00:12:04 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTING_H

# define BUILTING_H

# include "../libft/libft.h"
# include "../execute_unit/execute.h"

int    ft_echo(char **args, t_list *env);
int    ft_cd(char **args, t_list **env);
int    ft_pwd(char **args, t_list *env);
int    ft_export(char **args, t_list *env);
int    ft_unset(char **args, t_list *env);
int    ft_env(char **args, t_list *env);
int    ft_exit(char **args);

#endif
