/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:52:34 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/10/17 13:12:25 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memmove(p, s1, ft_strlen(s1));
	return (p);
}
