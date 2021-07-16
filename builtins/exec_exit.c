#include "../minishell.h"

void	exec_exit(t_all *all)
{
	(void)all;
	ft_putendl_fd("exit", 1);
	exit(0);
}
