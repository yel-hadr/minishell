#include "execute.h"

int ft_exec_the_cmd(t_cmd *cmd, t_list **envp)
{
  int status;

  status = 0;
  if (cmd->args[0] && is_builting(cmd->args[0]))
    status = exec_builting(cmd, envp);
  else {
    char **env = ft_lst_to_char(*envp);
    status = ft_execute(cmd, env);
  }
  exit(status);
  return (status); 
}

int execute(t_cmd *cmd, t_list **envp)
{
  int		status;

  status = 0;
  if (cmd == NULL)
    return (1);
  if (!cmd->next && is_builting(cmd->args[0]))
  {
    status = execute(cmd, envp);
  }
  else
  {
    status = ft_pipe(cmd, envp);
  }
  return (status);
}

