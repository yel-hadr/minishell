/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 06:30:14 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/12 00:01:38 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"


static char	*get_redir_symbol(char *symbol)
{
	int	skip;

	if (!symbol)
		return (NULL);
	skip = 1;
	if (symbol[0] && symbol[1] && symbol[0] == symbol[1])
		skip = 2;
	symbol += skip;
	return (symbol);
}

static int	checking_redir(t_cmd *cmd)
{
	int	i;
	int	len;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (cmd->redir_sym[++i] && !tmp)
	{
		len = ft_strlen(cmd->redir_sym[i]);
		if (len <= 2 && (!ft_strncmp("HEREDOC", cmd->redir_sym[i], len) || !ft_strncmp("APPEND", cmd->redir_sym[i], len)))
		{
			if (!ft_strlen(cmd->redir_files[i]))
				tmp = "syntax error near unexpected token `newline'";
		}
		else
			tmp = get_redir_symbol(cmd->redir_sym[i]);
	}
	if (!tmp)
		return (0);
	ft_putstr_fd("mish: syntax error near unexpected token `", 2);
	ft_putendl_fd(tmp, 2);
	free(tmp);
	return (1);
}

int	split_redir(t_cmd *cmd)
{
	int	lenth;
	int	i;
	char	**get_redir;

	i = -1;
	lenth = 0;
	get_redir = get_redirections(cmd->cmd);
	while (get_redir[++i])
		lenth++;
	cmd->redir_files = (char **)ft_calloc(sizeof(char *) , (lenth + 1));
	cmd->redir_sym = (char **)ft_calloc(sizeof(char *) , (lenth + 1));
	i = -1;
	while (get_redir[++i])
	{
		cmd->redir_files[i] = get_redir[i];
		cmd->redir_sym[i] = get_redir_symbol(get_redir[i]);
	}
	cmd->redir_files[i] = NULL;
	cmd->redir_sym[i] = NULL;
	free(get_redir);
	return (checking_redir(cmd));
}

// int main()
// {
// 	t_cmd *cmd;
// 	int i=0;
// 	cmd = (t_cmd *)malloc(sizeof(t_cmd));
// 	cmd->cmd = "ls -l > file > file2 >> file3 < file4 << file5";
// 	split_redir(cmd);
// 	while (cmd->redir_files)
// 	{
// 		printf("file: %s\n", cmd->redir_files[i]);
// 		cmd->redir_files++;
// 	}
// 	return (0);
// }
