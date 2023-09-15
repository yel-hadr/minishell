/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:54:43 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/09 08:21:09 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int main()
{
	printf("%d\n",ft_isdigit('5'));
    printf("%d\n",ft_isdigit('H'));
    printf("%d\n",ft_isdigit('&'));
    printf("%d\n",ft_isdigit(200));
    printf("%d\n",ft_isdigit(0));
}
*/
