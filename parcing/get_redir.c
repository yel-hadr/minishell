/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:17:38 by elakhfif          #+#    #+#             */
/*   Updated: 2023/07/06 21:38:38 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*next_redirection(char *input)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (input[i])
	{
		if (input[i] == '\'' && !dq)
			sq = !sq;
		if (input[i] == '\"' && !sq)
			dq = !dq;
		if (ft_strchr("><", input[i]) && !sq && !dq)
			return (input + i);
		i++;
	}
	return (NULL);
}

static int	skip_spaces(char *input)
{
	int	i;

	i = 0;
	while (input[i] && ft_isspace(input[i]))
		i++;
	return (i);
}

static char	*get_redirection(char *input, int *type)
{
	int		i;
	int		sq;
	int		dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (input[i])
	{
		if (input[i] == '\'' && !dq)
			sq = !sq;
		if (input[i] == '\"' && !sq)
			dq = !dq;
		if (input[i] == '>' && !sq && !dq)
		{
			if (input[i + 1] == '>')
				*type = APPEND;
			else
				*type = REDIR_OUT;
			return (input + i);
		}
		i++;
	}
	return (NULL);
}

static int	count_redirections(char *input)
{
	int		i;
	int		sq;
	int		dq;
	int		count;

	i = 0;
	sq = 0;
	dq = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '\'' && !dq)
			sq = !sq;
		if (input[i] == '\"' && !sq)
			dq = !dq;
		if (input[i] == '>' && !sq && !dq)
			count++;
		i++;
		input = next_redirection(input);
	}
	return (count);
}

char	**get_redirections(char *input)
{
	char	**redirections;
	int		i;
	int		type;

	i = 0;
	if (!(redirections = (char **)malloc(sizeof(char *) *
					(count_redirections(input) + 1))))
		return (NULL);
	while (*input)
	{
		input += skip_spaces(input);
		if (!(redirections[i] = get_redirection(input, &type)))
			break ;
		if (type == APPEND)
			input += 2;
		else
			input++;
		redirections[i] = ft_substr(input, 0, ft_strlen(input) -
				ft_strlen(next_redirection(input)));
		input += ft_strlen(redirections[i]);
		i++;
	}
	redirections[i] = NULL;
	return (redirections);
}

// int	main()
// {
// 	char	**redirections;
// 	int		i;
//
// 	i = 0;
// 	redirections = get_redirections("echo 'hello' > file1 >> file2 > file3");
// 	while (redirections[i])
// 	{
// 		printf("%s\n", redirections[i]);
// 		i++;
// 	}
// 	return (0);
// }
