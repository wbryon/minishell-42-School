#include "minishell.h"

t_history 	*hist_new(char *content)
{
	t_history	*new;

	new = malloc(sizeof(t_history));
	new->tmp = content;
	new->next = NULL;
	new->prev = NULL;
	new->prime = NULL;
	return (new);
}

void	hist_add(t_history **lst, t_history *new)
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

void 	read_line(char *buf, t_all *all)
{
	char	*tmp;

	tmp = all->cur_history->tmp;
	all->cur_history->tmp = ft_strjoin(all->cur_history->tmp, buf);
	free(tmp);
}