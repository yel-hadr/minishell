/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:00:07 by elakhfif          #+#    #+#             */
/*   Updated: 2023/06/16 10:44:14 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	quote_type(char c)
{
	if (c == '\'')
		return (1);
	else if (c == '\"')
		return (2);
	return (0);
}

int	quote_closed(char *str, int i)
{
	int		type;

	type = quote_type(str[i]);
	i++;
	while (str[i] && quote_type(str[i]) != type)
		i++;
	if (!str[i])
		return (0);
	return (1);
}

int	quote_len(char *str, int i)
{
	int		type;

	type = quote_type(str[i]);
	i++;
	while (str[i] && quote_type(str[i]) != type && quote_closed(str, i))
		i++;
	return (i);
}

int	check_quotes(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
		{
			if (quote_closed(str, i) == 0)
				return (write(2, "quotes are not closed\n", 22), 0);
			i = quote_len(str, i);

		}
		i++;
	}
	return (1);
}







int	skip_quotes(char *str, int i)
{
	int		type;

	type = quote_type(str[i]);
	i++;
	while (str[i] && quote_type(str[i]) != type)
		i++;
	return (i);
}

int	remove_quotes(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_quote(str[i]))
			i = skip_quotes(str, i);
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (1);
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		if (quotes(av[1]))
// 			printf("quotes are closed\n");
// 		else
// 			printf("quotes are not closed\n");
// 	}
// 	return (0);
// }
