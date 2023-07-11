#include "excute.h"

int ft_exec_the_cmd(t_cmd *cmd, t_list **envp)
{
  int status;

  if (cmd->args[0] && is_builting(cmd->args[0]))
    status = exec_builting(cmd, &envp);
  else
    status = ft_execute(cmd, envp);
}

int execute(t_cmd *cmd, t_list **envp)
{
  int		status;

  status = 0;
  if (cmd == NULL)
    return (1);
  if (!cmd->next)
    status = execute(cmd, envp);
  else 
    status = ft_pipe(cmd, envp);
  return (status);
}

