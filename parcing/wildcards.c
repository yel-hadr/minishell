/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:18:06 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/13 06:39:39 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static int	ms_match(char *wildcard, char *filename)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (wildcard[i] && filename[j])
	{
		if (wildcard[i] == '*')
		{
			while (wildcard[i] == '*')
				i++;
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

static char	**ms_filltab(char **tab, int i)
{
	DIR				*dir;
	struct dirent	*sd;
	int				j;

	j = 0;
	dir = opendir(".");
	if (dir == NULL)
		return (NULL);
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.')
		{
			tab[j] = ft_strdup(sd->d_name);
			j++;
		}
	}
	tab[j] = NULL;
	closedir(dir);
	return (tab);
}

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

char		**ms_wildcard(char *wildcard)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = (char **)ft_calloc(sizeof(char *) * (ms_filenumber() + 1));
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

int main()
{
	char **tab;
	int i = 0;
	tab = ms_wildcard("*.d");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return 0;
}
