/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:23:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/03 17:51:47 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// check if there is a space at the beginning of the line or at the end of the line or space not found
// return 1 if there is an error and 0 if there is no error !!!
int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
// check if there is a pipe at the beginning of the line or at the end of the line or pipe not found
// return 1 if there is an error and 0 if there is no error !!!
int check_pipe(char *str)
{
	int i;
	int flag;

	i = -1;
	flag = 0;
	while (str[i + 1] == ' ') // skip spaces at the beginning of the line
		i++;
	if (str[i + 1] == '|') // pipe at the beginning of the line 
		i = -2;
	while (i != -2 && str[++i]) // i = -2 if pipe at the end of the line or pipe not found
	{
		if (str[i] == '|')
			flag = 1;
		if (str[i] != ' ')
			flag = 0;
	}
	if (i == -2 || flag == 1)
	{
		printf("Error : pipe at the end of the line or pipe not found\n"); // error pipe at the end of the line or pipe not found 
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error : you should enter one argument\n");
		return (0);
	}
	if (is_space(av[1]) == 1)
	{
		printf("Error : space at the beginning of the line or at the end of the line or space not found\n");
		return (0);
	}
	if (check_pipe(av[1]) == 1)
		return (0);
	return (0);
}
