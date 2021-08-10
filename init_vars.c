#include "minishell.h"

void	init_vars(t_all *all)
{
	all->env = NULL;
	all->command_buf = NULL;
	all->parse.flag = 0;
	all->parse.count = 0;
	all->parse.quotes = 0;
	all->parse.dquotes = 0;
	all->cmd = NULL;
	all->flags.flag_d_red_in = 0;
	all->flags.flag_red_in = 0;
	all->flags.flag_d_red_out = 0;
	all->flags.flag_red_out = 0;
}