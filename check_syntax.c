#include "minishell.h"

int	check_quotes(t_all *all)
{
	int	i;
<<<<<<< HEAD
=======
>>>>>>> f1e51a8201dd8a443986cb8fbeb7c6ff28fcb530

	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '\'')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
<<<<<<< HEAD
			{
				if (all->s_c.s_quotes % 2 == 0)
					continue;
			}
			s_quotes++;
=======
				i++;
			else
				all->s_c.s_quotes++;
>>>>>>> f1e51a8201dd8a443986cb8fbeb7c6ff28fcb530
		}
	}
	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '"')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
<<<<<<< HEAD
			{
				if (all->s_c.d_quotes % 2 == 0)
					continue;
			}
			d_quotes++;
=======
				i++;
			else
				all->s_c.d_quotes++;
>>>>>>> f1e51a8201dd8a443986cb8fbeb7c6ff28fcb530
		}
	}
	if (all->s_c.s_quotes % 2 != 0 || all->s_c.d_quotes % 2 != 0)
		return (1);
	return (0);
}