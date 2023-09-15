/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:10:42 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/13 06:40:48 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		indx;
	int		len;
	char	*str;

	indx = 0;
	len = ft_strlen(s1);
	str = ((char *)ft_calloc(sizeof(char) , (len +1)));
	if (str == NULL)
		return (NULL);
	while (indx < len)
	{
		str[indx] = s1[indx];
		indx++;
	}
	str[indx] = '\0';
	return (str);
}
/*
int main()
{
	char 	*str;
	char	*tmp = "HAHAHA \0 tu me vois pas !";
    int l = ft_strlen(tmp);
	str = ft_strdup(tmp);
	printf ("%d\n",ft_strncmp(str, tmp,l));
}
*/
