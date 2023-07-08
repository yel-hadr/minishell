/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:22:54 by elakhfif          #+#    #+#             */
/*   Updated: 2023/07/08 14:23:06 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s1;

	s1 = (char *)malloc(sizeof(char) * (size + 1));
	if (s1 == NULL)
		return (NULL);
	ft_memset(s1, '\0', size + 1);
	return (s1);
}
