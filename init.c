#include "minishell.h"

void	init_vars(t_all *all)
{
	all->command.count = 0;
	all->command.slash_flag = 0;
	all->command.sq_flag = 0;
	all->command.dq_flag = 0;
	all->command.s_quotes = 0;
	all->command.d_quotes = 0;
	all->command.semicolon = NULL;
}

int		prompt(t_all *all)
{
	int		ret;
	char	buf[MAXSIZE];
	char	*str;

	all->lexer_buff = malloc(sizeof(t_lexer));
	while (all->env)
	{
		init_vars(all);
		if (!all->history || (all->history && all->history->current[0] != '\0'))
			add_line_to_history(&all->history, init_history_list(ft_strdup("")));
		hist_move_to_end(all);
		init_termcap_functions(all);
		ft_putstr_fd("minishell> ", STDOUT);
		tputs(save_cursor, 1, ft_putchar);
		while (1)
		{
			ret = read(STDIN, &buf, BUFFER_SIZE);
			buf[ret] = '\0';
			if (check_string(buf, all))
				break ;
		}
		if (check_quotes(all))
		{
			ft_putstr_fd("Syntax error: the number of quotes is odd!\n", STDOUT);
			break ;
		}
		all->command.sq_flag = 0;
		all->command.slash_flag = 0;
		str = parser2(all);
		printf("str_final=%s\n", str);
		// if (*all->history->current)
		// {
		// 	parser(all);
		// 	execute(all);
		// }
	}
	return (0);
}