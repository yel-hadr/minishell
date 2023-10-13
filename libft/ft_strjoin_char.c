/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 04:11:57 by youssef           #+#    #+#             */
/*   Updated: 2023/10/12 04:18:42 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	next_var(char *str, int i)
{
	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '\"'
		&& str[i] != '\'' && str[i] != '\\' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_char(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + 2));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[++i] = '\0';
	free(s1);
	return (str);
}
