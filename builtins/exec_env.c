#include "../minishell.h"

void	exec_env(t_all *all)
{
	int	i;

	i = -1;
	if (all->cmd->args[1])
	{
		ft_putstr_fd("env: ", 1);
		ft_putstr_fd(all->cmd->args[1], 1);
		ft_putendl_fd(": No such file or directory", 1);
		return ;
	}
	if (all->env)
		while (all->env[++i])
			if (ft_strchr(all->env[i], '='))
				ft_putendl_fd(all->env[i], 1);
}
