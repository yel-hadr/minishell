/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:08:50 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/07 23:23:41 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./readline/readline.h"
#include "./readline/history.h"
#include "./libft/libft.h"

//next_quote function to get the next quote index !!
int	next_quote(char const *str, int start, char c)
{
	int i;

	start++;
	if (c == 39 || c == 34) // 39 == ' && 34 == "
	{
		i = start;
		while (str[i] && str[i] != c)
			i++;
		return (i); 	// return the index of the next quote
	}
	else 			// if c == ' ' or '\t'
	{
		i = start;
		while (str[i] && str[i] != c && str[i] != '\'' && str[i] != '\"') 
			i++;
		return (i);
	}
}

//wordslen function to get the number of words in the string !!
int	wordslen(char const *str, char c)
{
	int i;
	int wdlen;

	i = 0;
	wdlen = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			wdlen++;
			i = next_quote(str, i, c);
		}
		else
			i++;
	}
	return (wdlen);
}

//double_check function to check if the malloc is done or not !!
//if the malloc is done, we copy the word in the tab !!
//if the malloc is not done, we return 0 !!
int	double_check(char const *str, char c, char **cmd)
{
	int i;
	int cmdlen;
	int last;

	i = 0;
	cmdlen = 0;
	last = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			last = next_quote(str, i, c);
			cmd[cmdlen] = (char *)malloc(sizeof(char) * (last - i + 1));
			if (!cmd[cmdlen])
				return (0);
			cmd[cmdlen] = strncpy(cmd[cmdlen], str + i, last - i);
			cmd[cmdlen][last - i] = '\0';
			cmdlen++;
			i = last;
		}
		else
			i++;
	}
	return (1);
}

//ultimate_split function to split the string !!
//we call the wordslen function to get the number of words in the string !!
//we call the double_check function to check if the malloc is done or not !!
//if the malloc is done, we copy the word in the tab !!
//if the malloc is not done, we return NULL !!
char	**ultimate_split(char const *str, char c)
{
	char	**cmd;
	int		wdlen;

	if (!str)
		return (NULL);
	wdlen = wordslen(str, c);
	cmd = (char **)malloc(sizeof(char *) * (wdlen + 1));
	if (!cmd)
		return (NULL);
	cmd[wdlen] = NULL;
	if (!double_check(str, c, cmd))
		return (NULL);
	return (cmd);
}

static int	*check_quotes(char *cmd, int i)
{
	int	quotes;

	quotes = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '\"')
		{
			i = next_quote(cmd, i, cmd[i]);
			quotes = 1;
		}
		else if (cmd[i] == ' ' || cmd[i] == '\t')
		{
			while (cmd[i] == ' ' || cmd[i] == '\t')
				i++;
			quotes = 1;
		}
		else
			i++;
		if (quotes == 1)
			break ;
	}
	return (0);
}

static int	*split_input(char *input)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	tab = (int *)malloc(sizeof(int) * 2);
}

int main()
{
	char *cmd;
	char *input;
	int  i;

	i = 0;
	while (1)
	{
		input = readline("[ tarzanshell ]: ");
		add_history(input);
		cmd = input;
		while (*cmd)
		{
			printf("[%d]= %s\n",++i, cmd);
			break ;
		}
		free(input);
	}
	return (0);
}
