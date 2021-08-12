#include "minishell.h"

int	execution(t_all *all)
{
	if (all->cmd->next)
		exec_pipe(all);
	else
	{
		exec_single(all);
	}
	return (0);
}