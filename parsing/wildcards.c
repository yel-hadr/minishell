/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:18:06 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/09 01:10:06 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

// match is function to check if the wildcard match the filename or not and return 1 if it match and 0 if not !
static int	ms_match(char *wildcard, char *filename)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (wildcard[i] && filename[j])
	{
		if (wildcard[i] == '*')
		{
			while (wildcard[i] == '*')
				i++;
			if (wildcard[i] == '\0')
				return (1);
			while (filename[j] && wildcard[i] != filename[j])
				j++;
		}
		if (wildcard[i] != filename[j])
			return (0);
		i++;
		j++;
	}
	if (wildcard[i] == filename[j])
		return (1);
	return (0);
}

// filenumber is function to count the number of files in the directory without the hidden files
static int	ms_filenumber(void)
{
	DIR				*dir;
	struct dirent	*sd;
	int				i;

	i = 0;
	dir = opendir(".");
	if (dir == NULL)
		return (0);
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.')
			i++;
	}
	closedir(dir);
	return (i);
}

// fill the tab is function to fill the tab with the files in the directory without the hidden files
// DIR is a structure that contains information about a directory, and struct dirent is a structure that contains information about an directory entry.
static char **ms_filltab(char **tab, int i)
{
	DIR				*dir;
	struct dirent	*sd;

	dir = opendir(".");
	if (dir == NULL)
		return (NULL);
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.')
		{
			tab[i] = ft_strdup(sd->d_name);
			i++;
		}
	}
	closedir(dir);
	return (tab);
}

// sort the tab is function to sort the tab in alphabetical order
static char	**ms_sorttab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = i;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

// wildcard is function to return the tab of the files that match the wildcard
char	**ms_wildcard(char *wildcard)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char **)ft_calloc(sizeof(char *) * (ms_filenumber() + 1), 1);
	tab = ms_filltab(tab, i);
	while (tab[i])
	{
		if (ms_match(wildcard, tab[i]))
		{
			tab[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	tab = ms_sorttab(tab);
	return (tab);
}
int	main(void)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ms_wildcard("*");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
