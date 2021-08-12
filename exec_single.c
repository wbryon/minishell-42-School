#include "minishell.h"

void	exec_single(t_all *all)
{
	
	if (!ft_strcmp(all->cmd->name, "echo"))
		exec_echo(all);
	else if (!ft_strcmp(all->cmd->name, "env"))
		exec_env(all);
	else if (!ft_strcmp(all->cmd->name, "pwd"))
		exec_pwd();
	else if (!ft_strcmp(all->cmd->name, "export"))
		exec_export(all);
	else if (!ft_strcmp(all->cmd->name, "unset"))
		exec_unset(all);
	else if (!ft_strcmp(all->cmd->name, "cd"))
		exec_cd(all);
	else if (!ft_strcmp(all->cmd->name, "exit"))
		exec_exit(all);
	else
		exec_bin(all);
}
