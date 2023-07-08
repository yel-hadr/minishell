/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wd_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:19:11 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/24 16:53:18 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	new_strlen(char *str, char *fword, char *sword)
{
	size_t	fword_len;
	size_t	sword_len;
	size_t	str_len;

	fword_len = ft_strlen(fword);
	sword_len = ft_strlen(sword);
	str_len = ft_strlen(str);
	while (str && fword && str[0])
	{
		if (!ft_strncmp(str, fword, fword_len))
			return (str_len - fword_len + sword_len);
		str++;
		str_len--;
	}
	return (str_len);
}

static char	*replaced_str(char *str, char *fword, char *sword)
{
	char	*new_str;
	int	count;
	size_t	new_len;

	new_len = new_strlen(str, fword, sword);
	new_str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!new_str)
		return (NULL);
	count = 0;
	while (str && fword && str[0])
	{
		if (!ft_strncmp(str, fword, ft_strlen(fword)))
		{
			ft_strcpy(new_str + count, sword);
			count += ft_strlen(sword);
			str += ft_strlen(fword);
		}
		else
			new_str[count++] = *str++;
	}
	new_str[count] = '\0';
	return (new_str);
}

char		*wd_replace(char *str, char *fword, char *sword, int free_str)
{
	char	*new_str;

	new_str = replaced_str(str, fword, sword);
	if (free_str)
		free(str);
	return (new_str);
}

// int	main()
// {
// 	char	*str;
// 	char	*new_str;
//
// 	str = ft_strdup("hello world");
// 	new_str = wd_replace(str, "hello", "hi", 1);
// 	printf("%s\n", new_str);
// 	return (0);
// }
