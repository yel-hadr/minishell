/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:34:59 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/10/08 20:02:58 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (start < end && (ft_strchr(set, s1[start]) || \
				ft_strchr(set, s1[end])))
	{
		if (ft_strchr(set, s1[start]))
			start++;
		if (ft_strchr(set, s1[end]))
			end--;
	}
	if (start == end && ft_strchr(set, s1[end]))
		return (ft_strdup(""));
	p = ft_calloc(sizeof(char), (end - start) + 2);
	if (!p)
		return (NULL);
	ft_memmove(p, s1 + start, (end - start) + 1);
	return (p);
}
