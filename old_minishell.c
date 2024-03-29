#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	// int		i;
	t_all	all;
	char	*str;
	char	*pwd;
	// char	**cmds;
	// char	**args;
	// t_cmd	*cmd;
	// t_cmd	*cmd_list;
	// t_cmd	*temp;

	(void)argv;
	(void)argc;
	ft_bzero(&all, sizeof(all));
	all.env = copy_env(envp, NULL);
	pwd = 0;
	pwd = getcwd(pwd, 0);
	init_vars(&all);
	while (1)
	{
		all.command_buf = readline("minishell> ");
		if (check_quotes(&all))
		{
			ft_putstr_fd("Syntax error: the number of quotes is odd!\n", STDOUT);
		}
		if (ft_strlen(all.command_buf) > 0)
			add_history(all.command_buf);
		str = parser(&all);
		// printf("|str_final=%s|\n", str);
		// cmds = ft_split(str, ';');
		// i = -1;
		// while (cmds[++i])
		// {
		// 	printf("cmds[%d]: |%s|\n", i, cmds[i]);
		// 	args = ft_split(cmds[i], ' ');
		// 	cmd = new_elem(args);
		// 	if (!cmd)
		// 		exit(1);
		// 	elem_add_back(&cmd_list, cmd);
		// 	free(cmds[i]);
		// }
		// free(cmds);
		// temp = cmd_list;
		// while (temp)
		// {
		// 	i = -1;
		// 	while (temp->args[++i])
		// 		printf("temp[%d]: |%s|\n", i, temp->args[i]);
		// 	temp = temp->next;
		// }
		all.cmd.args = ft_split(str, ' ');
		exec_builtin(&all);
		// free_list(cmd_list);
		// if (check_string(buf, &all))
			// break ;
	}
	return (0);
}