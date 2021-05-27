#include "minishell.h"

void	init_vars(t_all *all)
{
	all->s_c.count = 0;
	all->s_c.s_quotes = 0;
	all->s_c.d_quotes = 0;
	all->s_c.semicolon = NULL;
}