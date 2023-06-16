/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 09:52:20 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/16 18:07:39 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "parser.h"

// static int    next_variable(char *str, int i) 
// {
//     while (!ft_strchr("$", str[i]) && str[i] != '\0')
//         i++;
//     return (i);
// }
// static char    *get_variable_name(char *str)
// {
// 	char	*name;
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	j = 0;
// 	while (str[i] && str[i] != '$')
// 		i++;
// 	if (str[i] == '\0')
// 		return (NULL);
// 	i++;
// 	if (str[i] == '?')
// 		return (ft_strdup("?"));
// 	while (str[i] && !ft_strchr(" $", str[i]))
// 	{
// 		i++;
// 		j++;
// 	}
// 	name = ft_substr(str, i - j, j);
// 	return (name);
// }
//
// char    *replace_variable(char *str, int index)
// {
//     int    i;
//
//     i = 0;
//     while (str[i] && !ft_strchr(" $", str[i]))
//         i++;
//     if (str[i] == '\0' || str[i] == ' ')
//         return (str);
//     if (str[i] == '$')
//     {
//         if (str[i + 1] == '?')
//             return (ft_strjoin(ft_substr(str, 0, i), ft_itoa(errno)));
//         else
//             return (ft_strjoin(ft_substr(str, 0, i), getenv(get_variable_name(str + i))));
//     }
//     return (str);
// }

int    main(void)
{
    char *str = "$$";
    printf("%s\n", replace_variable(str, 0));
    return (0);
}
