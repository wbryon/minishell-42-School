#include "minishell.h"

void	exec_builtin(t_all *all)
{
	if (!ft_strcmp(all->cmd.args[0], "echo"))
		exec_echo(all);
	else if (!ft_strcmp(all->cmd.args[0], "env"))
		exec_env(all);
	else if (!ft_strcmp(all->cmd.args[0], "pwd"))
		exec_pwd();
	else if (!ft_strcmp(all->cmd.args[0], "export"))
		exec_export(all);
	else if (!ft_strcmp(all->cmd.args[0], "unset"))
		exec_unset(all);
	else if (!ft_strcmp(all->cmd.args[0], "cd"))
		exec_cd(all);
	else if (!ft_strcmp(all->cmd.args[0], "exit"))
		exec_exit(all);
	else
		exec_bin(all);
}
