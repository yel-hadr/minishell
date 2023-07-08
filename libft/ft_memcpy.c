/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:05:41 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/26 05:13:32 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*str1;

	i = 0;
	dest1 = (unsigned char *)dest;
	str1 = (unsigned char *)str;
	if (!dest && !str)
		return (NULL);
	while (i < n)
	{
		dest1[i] = str1[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
	int a;
	int	b = 513;
	int *s = ft_memcpy(&a, &b, 1);
	printf("%d\n", s[0]);

	char str[] = "TARZANdhghfgh";
    char str1[] = "MALIK";
    printf("%s\n%s", str, str1);
}
*/
