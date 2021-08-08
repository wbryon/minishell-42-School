#include "minishell.h"

char	**split_redirect(t_all *all, char *str)
{
	int		i;
	char	**args;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr(">", str[i]))
		{
			if (str[i + 1] == '>')
			{
				all->cmd.flag_d_red_out = 1;
				args = ft_splitset(str, " >\t");
			}
			else
			{
				all->cmd.flag_red_out = 1;
				args = ft_splitset(str, " >\t");
			}
		}
		else if (ft_strchr("<", str[i]))
		{
			if (str[i + 1] == '<')
			{
				all->cmd.flag_d_red_in = 1;
				args = ft_splitset(str, " <\t");
			}
			else
			{
				all->cmd.flag_red_in = 1;
				args = ft_splitset(str, " <\t");
			}
		}
	}
	return (args);
}

int	split_pipe(t_all *all, char *str)
{
	int		i;
	char	**cmds;

	i = -1;
	cmds = NULL;
	if (ft_strchr("|", str[i]))
	{
		if (str[0] == '|')
			ft_putstr_fd("syntax error near unexpected token `|'\n", STDOUT);
		cmds = ft_split(str, '|');
	}
	while (cmds[++i])
	{
		all->pipe = new_pipe(cmds[i]);
		if (!all->pipe->pipe_list)
			exit(1);
		printf("list=|%s|\n", all->pipe->pipe_list);
		//pipe_add_back(all->pipe->pipe_list, all->pipe);
		free(cmds[i]);
	}
	return (0);
}
