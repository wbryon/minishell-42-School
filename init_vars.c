#include "minishell.h"

void	init_vars(t_all *all)
{
	all->parse.flag = 0;
	all->parse.count = 0;
	all->parse.quotes = 0;
	all->parse.dquotes = 0;
	all->cmd.flag_d_red_in = 0;
	all->cmd.flag_red_in = 0;
	all->cmd.flag_d_red_out = 0;
	all->cmd.flag_red_out = 0;
}