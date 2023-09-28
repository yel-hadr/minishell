/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 04:10:13 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/09 08:29:40 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"


static int	new_str_size(char *str, char *w0, char *w1)
{
	size_t	w0_len;
	size_t	w1_len;
	size_t	str_len;
	size_t	match_count;

	w0_len = ft_strlen(w0);
	w1_len = ft_strlen(w1);
	str_len = ft_strlen(str);
	match_count = 0;
	while (str && w0 && str[0])
	{
		if (!ft_strncmp(str, w0, w0_len))
			match_count++;
		str++;
	}
	return (str_len + ((w1_len - w0_len) * match_count));
}

static char	*replaced_str(char *str, char *w0, char *w1)
{
	char	*result;
	size_t	result_length;

	result_length = new_str_size(str, w0, w1);
	result = ft_calloc(result_length + 1, 1);
	while (str && str[0])
	{
		if (w0 && !ft_strncmp(str, w0, ft_strlen(w0)))
		{
			ft_strlcpy(result, w1, result_length + 1);
			result += ft_strlen(w1);
			str += ft_strlen(w0);
		}
		else
			*result++ = *str++;
	}
	result -= result_length;
	return (result);
}

char	*replace_all_words(char *str, char *w0, char *w1, int usefree)
{
	char	*result;

  result = NULL;
	result = replaced_str(str, w0, w1);
	if (usefree == 1)
		free(str);
	return (result);
}

char	*extract_branch(char *buff)
{
	int		i;
	char	**temp;
	char	*branch;

	i = -1;
	temp = ft_split(buff, '/');
	free(buff);
	while (temp[++i])
		branch = temp[i];
	branch[ft_strlen(branch)-1] = '\0';
	branch = replace_all_words(" (b)", "b", branch, 0);
	free(temp);
	return (branch);
}

char	*get_work_dir(void)
{
	char	*home_dir;
	char	*work_dir;
	size_t	work_len;
	size_t	home_len;

	home_dir = getenv("HOME");
	work_dir = getcwd(NULL, 0);
	home_len = ft_strlen(home_dir) - 1;
	work_len = ft_strlen(work_dir);
	if (!work_dir)
		return (NULL);
	if (home_dir && !ft_strncmp(work_dir, home_dir, home_len))
	{
		home_dir = ft_substr(work_dir, home_len, (work_len - home_len));
		home_dir[0] = '~';
		free(work_dir);
		return (home_dir);
	}
	return (work_dir);
}

char	*get_host_name(void)
{
	int		fd;
	char	*buff;

	buff = NULL;
	fd = open("/etc/hostname", O_RDONLY);
	if (fd > 0)
	{
		buff = ft_calloc(1024, 1);
		if (read(fd, buff, 1024) < 0)
      return (NULL);
	}
	close(fd);
	if (buff && buff[ft_strlen(buff)-1] == '\n')
		buff[ft_strlen(buff) - 1] = '\0';
	return (buff);
}

char	*get_branch_name(void)
{
	int		fd;
	char	*buff;

	buff = NULL;
	fd = open(".git/HEAD", O_RDONLY);
	if (fd > 0)
	{
		buff = ft_calloc(1024, 1);
		if (read(fd, buff, 1024) < 0)
      return (NULL);
	}
	close(fd);
	if (buff)
		return (extract_branch(buff));
	return (NULL);
}

char	*prompt_msg(void)
{
	char	*host;
	char	*dir;
	char	*branch;
	char	*prompt;

	host = get_host_name();
	dir = get_work_dir();
	branch = get_branch_name();
	prompt = ft_strdup("\033[1;36mmish\033[0m\033[1;34m:\033[0m\033[1;12mD\033[0m\033[1;32mB\033[0m\033[1;29m$\033[0m ");
	if (getenv("USER"))
		prompt = replace_all_words(prompt, "USER", getenv("USER"), 1);
	if (host)
		prompt = replace_all_words(prompt, "mish", host, 1);
	free(host);
	prompt = replace_all_words(prompt, "D", dir, 1);
	free(dir);
	prompt = replace_all_words(prompt, "B", branch, 1);
	free(branch);
	return (prompt);
}

char	*prompt(void)
{
	char	*input;
	char	*prompt_txt;

	prompt_txt = prompt_msg();
	input = readline(prompt_txt);
	free(prompt_txt);
	return (input);
}
