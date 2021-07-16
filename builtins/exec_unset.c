#include "../minishell.h"

static void	delete_env(t_all *all, int target)
{
	int		i;
	char	*tmp;

	tmp = all->env[target];
	i = 0;
	while (all->env[i])
		i++;
	all->env[target] = all->env[i - 1];
	all->env[i - 1] = NULL;
	free(tmp);
}

void	exec_unset(t_all *all)
{
	int	i;
	int	target;

	i = 0;
	while (all->cmd.args[++i])
	{
		target = search_env(all, all->cmd.args[i]);
		if (target >= 0)
			delete_env(all, target);
	}
}
