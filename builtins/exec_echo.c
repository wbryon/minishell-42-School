#include "../minishell.h"

void	exec_echo(t_all *all)
{
	int	i;
	int	new_line;

	new_line = 1;
	i = 0;
	if (all->cmd->args[i])
	{
		if (!ft_strcmp(all->cmd->args[i + 1], "-n"))
		{
			new_line = 0;
			i++;
		}
		while (all->cmd->args[++i])
		{
			ft_putstr_fd(all->cmd->args[i], 1);
			if (all->cmd->args[i + 1])
				ft_putchar_fd(' ', 1);
		}
	}
	if (new_line)
		ft_putchar_fd('\n', 1);
}
