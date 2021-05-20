#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	char	*tmp;
	char	buf[MAXSIZE];
	int		i;
	t_all	all;

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
		init_termcap_functions(&all);
		ft_putstr_fd("minishell> ", STDOUT);
		tputs(save_cursor, 1, ft_putchar);
		while (1)
		{
			ret = read(STDIN, &buf, BUFFER_SIZE);
			buf[ret] = '\0';
			if (ft_isprint(*buf))
			{
				write_line_to_hist(buf, &all);
				ft_putstr_fd(buf, 1);
			}
			else if (*buf == '\n')
				goto_new_prompt(&all);
			else if (!ft_strcmp(buf, "\e[A") || !ft_strcmp(buf, "\e[B"))//KEYS UP_DOWN
				up_down_keys(&all, buf);
			else if (*buf == '\177')//BACKSPACE
				do_backspace(all.history->current);
			else if (!ft_strcmp(buf, "\011"))//TAB
				tputs(cursor_normal, 1, ft_putchar);
			ft_bzero(buf, (int)ft_strlen(buf));
			ft_bzero(all.history->current, ft_strlen(all.history->current));
			write(STDOUT, "\n", 1);
		}
	}
	write(STDOUT, "\n", 1);
	return (0);
}