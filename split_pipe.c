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
			all->flags.flag_d_red_out = 1;
			args = ft_splitset(str, " >\t");
		}
		else
		{
			all->flags.flag_red_out = 1;
			args = ft_splitset(str, " >\t");
		}
	}
	else if (ft_strchr(str, '<'))
	{
		ptr = ft_strchr(str, '<');
		if (*(ptr + 1) == '<')
		{
			all->flags.flag_d_red_out = 1;
			args = ft_splitset(str, " <\t");
		}
		else
		{
			all->flags.flag_red_out = 1;
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
	char	**pipes;
	char	**args;
	t_cmd	*new;

	if (str[0] == '|')
		ft_putstr_fd("syntax error near unexpected token `|'\n", STDOUT);
	pipes = ft_split(str, '|');
	if (all->cmd)
	{
		free_list(all->cmd);
		all->cmd = NULL;
	}
	i = -1;
	while (pipes[++i])
	{
		args = ft_split(pipes[i], ' ');
		new = new_elem(args);
		if (!new)
			exit(1);
		elem_add_back(&all->cmd, new);
		free(pipes[i]);
	}
	free(pipes);
	return (0);
}
