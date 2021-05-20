#include "minishell.h"

int	init_termcap_functions(t_all *all)
{
	struct termios	term;

	if (!isatty(0))
		ft_putstr_fd("not a terminal!\n", 1);
	if (tcgetattr(0, &all->params) == -1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ISIG);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	if (tgetent(0, "xterm-256color") != 1)
	{
		ft_putstr_fd("error on tgetent\n", 1);
		exit(-1);
	}
	return (0);
}

int	do_backspace(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(delete_character, 1, ft_putchar);
		str[len - 1] = '\0';
	}
	return (0);
}

int	up_down_keys(t_all *all, char *buf)
{
	if (!ft_strcmp(buf, "\e[A"))
	{
		if (all->history->prev)
		{
			all->history = all->history->prev;
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tgetstr("cd", 0), 1, ft_putchar);
			ft_putstr_fd(all->history->current, 1);
		}
	}
	else if (!ft_strcmp(buf, "\e[B"))
	{
		if (all->history->next)
		{
			all->history = all->history->next;
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tgetstr("cd", 0), 1, ft_putchar);
			ft_putstr_fd(all->history->current, 1);
		}
	}
	return (0);
}

int	goto_new_prompt(t_all *all)
{
	char	*tmp;

	tcsetattr(0, TCSANOW, &all->params);
	if (!all->history->prime)
		all->history->prime = ft_strdup(all->history->current);
	else if (*all->history->current)
	{
		tmp = ft_strdup(all->history->current);
		free(all->history->current);
		all->history->current = ft_strdup(all->history->prime);
		hist_move_to_end(all);
		free(all->history->current);
		all->history->current = tmp;
	}
	return (write(1, "\n", 1));
}