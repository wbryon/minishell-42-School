#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	char	*tmp;
	char	buf[MAXSIZE];
	int		i;
	t_all	all;
	char	*str;

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
		if (!all.history || (all.history && all.history->current[0] != '\0'))
			add_line_to_history(&all.history, init_history_list(ft_strdup("")));
		printf("%s\n", all.history->current);
		hist_move_to_end(&all);
		init_termcap_functions(&all);
		ft_putstr_fd("minishell> ", STDOUT);
		tputs(save_cursor, 1, ft_putchar);
		while (1)
		{
			ret = read(STDIN, &buf, BUFFER_SIZE);
			buf[ret] = '\0';
			if (check_string(buf, &all))
				break ;
		}
		str = parser(&all);
	}
	return (0);
}