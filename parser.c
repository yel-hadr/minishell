/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:23:27 by elakhfif          #+#    #+#             */
/*   Updated: 2023/05/06 23:20:28 by elakhfif         ###   ########.fr       */
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
	while (str[i + 1] == ' ') 							//skip spaces at the beginning of the line
		i++;
	if (str[i + 1] == '|') 								//pipe at the beginning of the line 
		i = -2; 								//i = -2 if pipe at the beginning of the line
	while (i != -2 && str[++i]) 							//i = -2 if pipe at the end of the line or pipe not found
	{
		if (str[i] == '|')							//pipe found !
			flag = 1;
		if (str[i] != ' ')							//skip spaces !
			flag = 0;
	}
	if (i == -2 || flag == 1 || str[i - 1] == '|') 					
	{
		printf("Error : pipe at the end of the line or pipe not found\n");	
		return (1);
	}
	return (0);
}

