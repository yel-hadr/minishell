/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 06:45:55 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/07 04:12:28 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(const char *str, unsigned int n)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = (char *)ft_calloc(sizeof(char), (n + 1));
	if (!ptr)
		return (NULL);
	while (str[i] && i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
