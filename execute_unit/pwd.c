/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:35:30 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/08 17:22:40 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

int ft_pwd(void)
{
	char *str;
	
	str = ft_calloc(OPEN_MAX, sizeof(char));
	getcwd(str, OPEN_MAX);
	printf ("%s\n", str);
	return (0);
}