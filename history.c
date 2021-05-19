#include "minishell.h"

t_history 	*init_history_list(char *content)
{
	t_history	*new;

	new = malloc(sizeof(t_history));
	new->tmp = content;
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
	while (all->cur_history->next)
		all->cur_history = all->cur_history->next;
}

void 	read_line(char *buf, t_all *all)
{
	char	*tmp;

	tmp = all->cur_history->tmp;
	all->cur_history->tmp = ft_strjoin(all->cur_history->tmp, buf);
	free(tmp);
}