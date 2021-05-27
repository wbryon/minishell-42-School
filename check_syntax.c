#include "minishell.h"

int	check_quotes(t_all *all)
{
	int	i;
	int	s_quotes;
	int	d_quotes;

	i = -1;
	s_quotes = 0;
	d_quotes = 0;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '\'')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
			{
				if (s_quotes % 2 == 0)
					continue;
			}
			s_quotes++;
		}
	}
	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '"')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
			{
				if (d_quotes % 2 == 0)
					continue;
			}
			d_quotes++;
		}
	}
	if (s_quotes % 2 != 0 || d_quotes % 2 != 0)
		return (1);
	return (0);
}