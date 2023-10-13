/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:14:13 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/09 08:21:09 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
int main()
{
	char *str;

    str = "slimka";
    printf("%zu\n",ft_strlen(str));
    printf("%zu\n",ft_strlen(NULL));
    printf("%zu\n",ft_strlen('\0'));
    printf("%zu\n",ft_strlen(""));
}
*/
