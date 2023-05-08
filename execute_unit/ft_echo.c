/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:35:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/05/08 21:55:36 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_unit.h"

int ft_echo(int ac, char **av)
{
	int i;
	
	i = 1;
	if (!ft_strncmp("-n", av[1], ft_strlen("-n")))
		i = 2;
	while (i < ac)
	{
		write (1, av[i], ft_strlen(av[i]));
		if (i != ac - 1);
			write (1, " ", 1);
		i++;
	}
	if (ft_strncmp("-n", av[1], ft_strlen("-n")))
		write (1, "\n", 1);
}
