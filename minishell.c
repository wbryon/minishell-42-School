#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_all	all;
	// char	*str;
	char	*command_buf;
	char	*pwd;

	(void)argv;
	(void)argc;
	ft_bzero(&all, sizeof(all));
	i = 0;
	while (envp[i])
		i++;
	all.env = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i])
		all.env[i] = ft_strdup(envp[i]);
	all.env[i] = NULL;
	pwd = 0;
	pwd = getcwd(pwd, 0);
	while (all.env)
	{
		init_vars(&all);
		while (1)
		{
			command_buf = readline("minishell> ");
			if (ft_strlen(command_buf) > 0)
				add_history(command_buf);
			if (!ft_strcmp(command_buf, "exit"))
				return (1);
			else if (!ft_strcmp(command_buf, "\3"))
				command_buf = readline("minishell> ");
			// if (check_string(buf, &all))
				// break ;
		}
		// if (check_quotes(&all))
		// {
		// 	ft_putstr_fd("Syntax error: the number of quotes is odd!\n", STDOUT);
		// 	break ;
		// }
		// str = parser2(&all);
		// printf("|str_final=%s|\n", str);
	}
	return (0);
}