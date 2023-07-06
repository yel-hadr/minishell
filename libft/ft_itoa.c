/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:56:43 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/10/17 12:35:27 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*to_string(int nbr, char *str)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		str[i] = '-';
		to_string((nbr * -1), str);
	}
	else if (nbr > 9)
	{
		to_string((nbr / 10), str);
		to_string((nbr % 10), str);
	}
	else
	{
		while (str[i])
			str++;
		str[i] = nbr + '0';
	}
	return (str);
}

static int	count(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while ((nbr / 10) > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = ft_calloc(sizeof(char), count(n) + 2);
	if (!s)
		return (NULL);
	to_string(n, s);
	return (s);
}
