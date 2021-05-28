#include "minishell.h"

void	check_s_quotes(t_all *all)
{
	int	i;
	int	s_quotes;

	i = -1;
	s_quotes = 0;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '\'')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
			{
				if (all->s_c.s_quotes && all->s_c.s_quotes % 2 != 0)
					all->s_c.s_quotes++;
				else
					continue ;
			}
			else
				all->s_c.s_quotes++;
		}
	}
}

void	check_d_quotes(t_all *all)
{
	int	i;

	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '"')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
			{
				if (all->s_c.d_quotes && all->s_c.d_quotes % 2 != 0)
					all->s_c.d_quotes++;
				else
					continue ;
			}
			else
				all->s_c.d_quotes++;
		}
	}
}
	
int	check_quotes(t_all *all)
{
	check_s_quotes(all);
	check_d_quotes(all);
	if (all->s_c.s_quotes % 2 != 0 || all->s_c.d_quotes % 2 != 0)
		return (1);
	return (0);
}