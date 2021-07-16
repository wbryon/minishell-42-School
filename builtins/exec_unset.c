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

static int	search_env(t_all *all, char *key)
{
	int	i;
	int	idx;

	idx = ft_strlen(key);
	i = -1;
	while (all->env[++i])
	{
		if (!ft_strncmp(all->env[i], key, idx) && \
			(all->env[i][idx] == '=' || \
			all->env[i][idx] == '\0'))
			return (i);
	}
	return (0);
}

void	exec_unset(t_all *all)
{
	int	i;
	int	target;

	i = 0;
	while (all->cmd.args[++i])
	{
		target = search_env(all, all->cmd.args[i]);
		delete_env(all, target);
	}
}
