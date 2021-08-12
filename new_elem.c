#include "minishell.h"

void    free_list(t_cmd *list)
{
    // int     i;
    t_cmd   *del;
    t_cmd   *cur;

    cur = list;
    while (cur)
    {
        del = cur;
        cur = cur->next;
        // i = -1;
        // while (del->args[++i])
            // free(del->args[i]);
        free(del->args);
        free(del);
    }
}

static t_cmd   *elem_last(t_cmd *cmds)
{
    if (cmds)
    {
        while (cmds->next)
            cmds = cmds->next;
        return (cmds);
    }
    return (NULL);
}

void    elem_add_back(t_cmd **cmds, t_cmd *new)
{
    t_cmd   *last;

    last = elem_last(*cmds);
    if (last)
        last->next = new;
    else
        *cmds = new;
}

t_cmd   *new_elem(char **args)
{
    t_cmd   *new;

    new = malloc(sizeof(t_cmd));
    if (new)
    {
        new->args = args;
        new->next = NULL;
    }
    return (new);
}
