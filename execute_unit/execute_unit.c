/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_unit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:54:26 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/11 18:18:05 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"


int main (int ac, char *av[], char *aenv[])
{
	(void)av;
	(void)ac;
	t_list *env;

	env = ft_creat_env(aenv);
}
