#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	int		status;
	char	*line;
	t_main	main;

	(void)argc;
	(void)argv;
	while (status)
	{
		ft_putstr_fd("sh> ", 1);
		get_next_line(1, line);
		parcer(line, &main);
		executor(&main, env);
	}
	return (0);
}
