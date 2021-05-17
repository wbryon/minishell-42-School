#include "minishell.h"

void 	get_history(char *buf, t_all *all)
{
	char	*tmp;

	tmp = all->cur_history->tmp;
	all->cur_history->tmp = ft_strjoin(all->cur_history->tmp, buf);
	free(tmp);
}