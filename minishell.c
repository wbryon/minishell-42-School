#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_all	all;

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
	//all.env[i] = NULL;
	prompt(&all);
	return (0);
}