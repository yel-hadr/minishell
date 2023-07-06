/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:23:14 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/10/04 01:37:44 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen(dst);
	if (len >= dstsize)
		return (dstsize + ft_strlen(src));
	else
	{
		while (src[index] && index < (dstsize - len -1))
		{
			dst[len + index] = src[index];
			index++;
		}
	}
	dst[len + index] = '\0';
	return (len + ft_strlen(src));
}
