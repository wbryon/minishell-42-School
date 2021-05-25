#include "minishell.h"

int	check_quotes(t_all *all)
{
	int		i;

	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '\'')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
				i++;
			all->s_c.s_quotes++;
		}
	}
	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '"')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
				i++;
			all->s_c.d_quotes++;
		}
	}
	if (all->s_c.s_quotes % 2 != 0 || all->s_c.d_quotes % 2 != 0)
		return (1);
	return (0);
}