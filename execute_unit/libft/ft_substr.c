/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:10:40 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/10/18 15:21:38 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memmove(p, &s[start], len);
	return (p);
}
