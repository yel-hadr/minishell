/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:54:32 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/10/17 13:10:59 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start_char(const char *str, char c, size_t b)
{
	while (str[b] && str[b] == c)
		b++;
	return (b);
}

static size_t	end_char(const char *str, char c, size_t i)
{
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	b;
	size_t	count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		i = start_char(s, c, i);
		b = end_char(s, c, i);
		if (i < b)
			count++;
		i = b;
	}
	return (count);
}

static void	split(char **r, char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	b;

	i = 0;
	count = 0;
	while (s[i])
	{
		i = start_char(s, c, i);
		b = end_char(s, c, i);
		if (i < b)
			r[count++] = ft_substr(s, i, (b - i));
		i = b;
	}
	r[count] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!result)
		return (NULL);
	split(result, s, c);
	return (result);
}
