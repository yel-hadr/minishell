/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:04:58 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/09 08:21:09 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*frst;
	unsigned char	*scnd;
	int				i;

	i = 0;
	frst = (unsigned char *)s1;
	scnd = (unsigned char *)s2;
	while (n--)
	{
		if (frst[i] != scnd[i])
			return (frst[i] - scnd[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
        char k[] = "fallahi";
        char l[] = "fellahi";

        printf("%d\n",ft_memcmp(k,l,1));
}
*/
