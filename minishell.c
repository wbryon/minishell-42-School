#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		j;
	t_all	all;
	char	*str;
	char	*pwd;
	char	**cmds;
	char	**args;
	t_cmd	*cmd;
	t_cmd	*cmd_list;
	//t_cmd	*temp;

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
			ft_putstr_fd("Syntax error: the number of quotes is odd!\n", STDOUT);
		if (ft_strlen(all.command_buf) > 0)
			add_history(all.command_buf);
		str = parser(&all);
		printf("str=|%s|\n", str);
		cmds = ft_split(str, '|'); // деление строк по пайпам
		i = -1;
		while (cmds[++i])
		{
			args = split_redirect(&all, cmds[i]); // делим строку для получения команд и аргументов
			cmd = new_elem(args); //записываем команды и арг-ты в список
			printf("flag=|%d|\n", all.cmd.flag_red_out);
			if (!cmd)
				exit(1);
			elem_add_back(&cmd_list, cmd);
			free(cmds[i]);
			free(args);
		}
		free(cmds);
		//temp = cmd_list;
		while (cmd_list)
		{
			i = -1;
			while (cmd_list->args[++i])
			{
				printf("args_before[%d]=|%s|\n", i, cmd_list->args[i]);
				j = -1;
				while (cmd_list->args[i][++j])
				{
					decoder(&cmd_list->args[i], &j);
					printf("args[%d]=|%s|\n", i, cmd_list->args[i]);
				}
			}
			cmd_list = cmd_list->next;
		}
		// exec_builtin(&all);
		// free_list(cmd_list);
		// if (check_string(buf, &all))
			// break ;
	}
	return (0);
}