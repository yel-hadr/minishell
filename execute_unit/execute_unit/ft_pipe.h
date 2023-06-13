/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:44:58 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/13 19:41:25 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPE_H

# define FT_PIPE_H

# include "../libft/libft.h"
# include "execute_the_cmd.h"

int	ft_pipe(t_list *cmds, char **envp);

#endif
