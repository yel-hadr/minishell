/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:31:05 by yel-hadr          #+#    #+#             */
/*   Updated: 2023/06/17 15:33:20 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builting.h"

int ft_exit(char **args)
{
	if (args[1])
		exit(ft_atoi(args[1]));
	exit(0);
}

int main(int argc, char **argv)
{
	ft_exit(argv);
	return (0);
}