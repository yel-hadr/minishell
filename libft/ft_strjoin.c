/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:22:02 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/08 05:19:40 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lenth1;
	size_t	lenth2;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	lenth1 = ft_strlen(s1);
	lenth2 = ft_strlen(s2);
	result = ft_calloc(lenth1 + lenth2 + 1, 1);
	if (result)
	{
		ft_memmove(result, s1, lenth1);
		ft_memmove(result + lenth1, s2, lenth2);
	}
	return (result);
}
/*
#include <stdio.h>

int main()
{
	char	*s1 = "my favorite thing is ";
	char	*s2 = "profile ";
	char	*s3 = "DIAL 7ARZAN";
	printf("%s\n",ft_strjoin(ft_strjoin(s1, s2), s3));
}
*/
