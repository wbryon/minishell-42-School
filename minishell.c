#include "minishell.h"

int		sort_ft(char **buf)
{
	if (ft_strncmp(buf[0], "ls", ft_strlen(buf[0])) == 0)
		printf("ls-----\n");
	else
		printf("diff-----\n");
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	char	*tmp;
	char	buf[MAXSIZE];
	int		i;
	t_all	all;
	char	*term_name;
	struct	termios term;

	(void)argv;
	(void)argc;
	ft_bzero(&all, sizeof(all));
	tmp = NULL;
	i = -1;
	all.env = (char **)malloc(sizeof(envp));
	while (envp[++i])
		all.env[i] = ft_strdup(envp[i]);
	while (all.env)
	{
		if (!all.history || (all.history && all.history->current[0]))
			add_line_to_history(&all.history, init_history_list(ft_strdup("")));
		hist_move_to_end(&all);
		term_name = "xterm-256color";
		tcgetattr(0, &term);
		term.c_lflag &= ~(ECHO);
		term.c_lflag &= ~(ICANON);
		tcsetattr(0, TCSANOW, &term);
		tgetent(0, term_name);
		while (ft_strcmp(buf, "\4"))
		{
			tputs(save_cursor, 1, ft_putchar);
			ft_putstr_fd("minishell> ", STDOUT);
			while (strcmp(buf, "\n"))
			{
				ret = read(STDIN, &buf, BUFFER_SIZE);
				buf[ret] = '\0';
				if (ft_isprint(*buf))
				{
					read_line(buf, &all);
					ft_putstr_fd(buf, 1);
				}
				else if (!ft_strcmp(buf, "\e[A"))//KEY UP
				{
					if (all.history->prev)
					{
						all.history = all.history->prev;
						tputs(restore_cursor, 1, ft_putchar);
						tputs(tgetstr("cd", 0), 1, ft_putchar);
						ft_putstr_fd(all.history->current, 1);
					}
				}
				else if (!ft_strcmp(buf, "\e[B"))//KEY DOWN
				{
					if (all.history->next)
					{
						all.history = all.history->next;
						tputs(restore_cursor, 1, ft_putchar);
						tputs(tgetstr("cd", 0), 1, ft_putchar);
						ft_putstr_fd(all.history->current, 1);
					}
				}
				else if (!ft_strcmp(buf, "\177"))//BACKSPACE
				{
					int len = ft_strlen(all.history->current);
					//printf("%s\n", all.cur_history->tmp);
					if (len > 0)
					{
						tputs(cursor_left, 1, ft_putchar);
						tputs(delete_character, 1, ft_putchar);
						all.history->current[len - 1] = '\0';
					}
				}
				else if (!ft_strcmp(buf, "\011"))//TAB
					tputs(cursor_normal, 1, ft_putchar);
			}
			ft_bzero(buf, (int)ft_strlen(buf));
			ft_bzero(all.history->current, ft_strlen(all.history->current));
			write(STDOUT, "\n", 1);
		}
	}
	write(STDOUT, "\n", 1);
	return (0);
}