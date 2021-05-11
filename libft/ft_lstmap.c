#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_head;
	t_list *new_next;
	t_list *tmp;

	if (lst == NULL)
		return (NULL);
	if ((new_head = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	tmp = new_head;
	lst = lst->next;
	while (lst)
	{
		if ((new_next = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		tmp->next = new_next;
		tmp = new_next;
		lst = lst->next;
	}
	return (new_head);
}
