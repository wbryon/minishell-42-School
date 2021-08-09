#include "minishell.h"

char	**split_redirect(t_all *all, char *str)
{
	char	*ptr;
	char	**args;

	args = NULL;
	if (ft_strchr(str, '>'))
	{
		ptr = ft_strchr(str, '>');
		if (*(ptr + 1) == '>')
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
	else if (ft_strchr(str, '<'))
	{
		ptr = ft_strchr(str, '<');
		if (*(ptr + 1) == '<')
		{
			all->cmd.flag_d_red_out = 1;
			args = ft_splitset(str, " <\t");
		}
		else
		{
			all->cmd.flag_red_out = 1;
			args = ft_splitset(str, " <\t");
		}
	}
	else
		args = ft_splitset(str, " \t");
	return (args);
}

int	split_pipe(t_all *all, char *str)
{
	int		i;
	char	**cmds;

	if (str[0] == '|')
		ft_putstr_fd("syntax error near unexpected token `|'\n", STDOUT);
		cmds = ft_split(str, '|');
	i = -1;
	while (cmds[++i])
	{
		all->token = new_pipe(cmds[i]);
		if (!all->token)
			exit(1);
		pipe_add_back(&all->begin, all->token);
		free(cmds[i]);
	}
	return (0);
}
