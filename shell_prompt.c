#include "minishell.h"

int	init_termcap_functions(t_all *all)
{
	struct termios	new_params;

	//if (!isatty(0))
		//ft_putstr_fd("not a terminal!\n", 1);
	if (tcgetattr(0, &all->params) == -1)
		return (-1);
	tcgetattr(0, &new_params);
	new_params.c_lflag &= ~(ECHO);
	new_params.c_lflag &= ~(ISIG);
	new_params.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &new_params);
	if (tgetent(0, "xterm-256color") != 1)
	{
		ft_putstr_fd("error on tgetent\n", 1);
		exit(-1);
	}
	return (0);
}

int		new_prompt(t_all *all)
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

int	ctrl_c(t_all *all)
{
	//env_set_value(all, "?", "1");
	hist_move_to_end(all);
	free(all->history->current);
	all->history->current = ft_strdup("");
	tcsetattr(0, TCSANOW, &all->params);
	return (write(1, "\n", 1));
}

int		ctrl_d(t_all *all)
{
	if (*all->history->current == '\0')
	{
		tcsetattr(0, TCSANOW, &all->params);
		//ft_putendl_fd("Exit from minishell", 1);
		exit(0);
	}
	return (0);
}

int		check_string(char *buf, t_all *all)
{
	if (ft_isprint(*buf))
	{
		write_line_to_history(buf, all);
		ft_putstr_fd(buf, 1);
	}
	else if (!ft_strcmp(buf, "\3"))
		return (ctrl_c(all));
	else if (!ft_strcmp(buf, "\4"))
		return (ctrl_d(all));
	return (0);
}