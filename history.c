#include "minishell.h"

t_history 	*init_history_list(char *content)
{
	t_history	*new;

	new = malloc(sizeof(t_history));
	new->current = content;
	new->next = NULL;
	new->prev = NULL;
	new->prime = NULL;
	return (new);
}

void	add_line_to_history(t_history **lst, t_history *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (new)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		new->prev = *lst;
	}
}

void	hist_move_to_end(t_all *all)
{
	while (all->history->next)
		all->history = all->history->next;
}

void 	write_line_to_hist(char *buf, t_all *all)
{
	char	*tmp;

	tmp = all->history->current;
	all->history->current = ft_strjoin(all->history->current, buf);
	free(tmp);
}