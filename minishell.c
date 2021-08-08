#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		j;
	t_all	all;
	char	*str;
	char	*pwd;
	char	**args;
	t_cmd	*cmd;
	t_cmd	*cmd_list;
	t_cmd	*temp_cmd;
	t_pipe	*temp;

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
		split_pipe(&all, str); // деление строк по пайпам
		temp = all.pipe;
		while (temp)
		{
			args = split_redirect(&all, temp->pipe_list); // делим строку для получения команд и аргументов
			cmd = new_elem(args); //записываем команды и арг-ты в список
			if (!cmd)
				exit(1);
			elem_add_back(&cmd_list, cmd);
			free(args);
			temp = temp->next;
		}
		temp_cmd = cmd_list;
		while (temp_cmd)
		{
			i = -1;
			while (temp_cmd->args[++i])
			{
				j = -1;
				while (temp_cmd->args[i][++j])
					decoder(&temp_cmd->args[i], &j);
			}
			temp_cmd = temp_cmd->next;
		}
		// exec_builtin(&all);
		// free_list(cmd_list);
		// if (check_string(buf, &all))
			// break ;
	}
	return (0);
}