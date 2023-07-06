/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:31:32 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/10/17 13:14:39 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memmove(p, s1, ft_strlen(s1));
	ft_memmove(p + ft_strlen(s1), s2, ft_strlen(s2));
	return (p);
}
