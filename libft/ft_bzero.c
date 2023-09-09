/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:38:04 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/09 08:21:37 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
/*
int main()
{
    int t[4] = { 5, 4, 3, 2};
    ft_bzero(t,6);
    int i = 0;
    while(i < 4)
    printf("%d\n",t[i++]);
}
*/
