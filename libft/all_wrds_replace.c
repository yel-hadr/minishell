/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_wrds_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:19:13 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/07 04:08:49 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	new_str_len(char *str, char *fword, char *sword)
{
	size_t	len;
	size_t	fword_len;
	size_t	sword_len;

	len = 0;
	fword_len = ft_strlen(fword);
	sword_len = ft_strlen(sword);
	while (str && str[0])
	{
		if (fword && !ft_strncmp(str, fword, fword_len))
		{
			len += sword_len;
			str += fword_len;
		}
		else
		{
			len++;
			str++;
		}
	}
	return (len);
}

static char	*replaced_str(char *str, char *fwd, char *swd)
{
	char	*res;
	size_t	len;

	len = new_str_len(str, fwd, swd);
	res = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (str && str[0])
	{
		if (fwd && !ft_strncmp(str, fwd, ft_strlen(fwd)))
		{
			ft_strlcat(res, swd, len + 1);
			str += ft_strlen(fwd);
		}
		else
		{
			res[ft_strlen(res)] = *str;
			str++;
		}
	}
	return (res);
}

char	*all_wrds_replace(char *str, char *fwd, char *swd, int usefree)
{
	char	*res;

	res = replaced_str(str, fwd, swd);
	if (usefree == 1)
	{
		free(str);
		free(fwd);
		free(swd);
	}
	return (res);
}

// int	main()
// {
// 	char	*str;
// 	char	*str1;
// 	char	*str2;
//
// 	str = ft_strdup("hello world");
// 	str1 = ft_strdup("world");
// 	str2 = ft_strdup("hi");
// 	printf("%s\n", replace_all_words(str, str1, str2, 1));
// 	return (0);
// }
