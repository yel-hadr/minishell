/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:22:54 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/13 06:43:10 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnew(size_t size)
{
	char *s1;

	s1 = (char *)ft_calloc(sizeof(char) , (size + 1));
	if (s1 == NULL)
		return (NULL);
	ft_memset(s1, '\0', size + 1);
	return (s1);
}
