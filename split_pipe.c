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
	int		j;
	char	**pipes;
	char	*name;
	char	*args;
	t_cmd	*new;

	if (str[0] == '|')
		ft_putstr_fd("syntax error near unexpected token `|'\n", STDOUT);
	pipes = ft_split(str, '|');
	i = -1;
	all->cmd_total = 0;
	while (pipes[++i])
	{
		(all->cmd_total)++;
		pipes[i] = ft_strtrim(pipes[i], " \t");
		j = 0;
		while (pipes[i][j] != ' ' && pipes[i][j] != '>' && pipes[i][j] != '<' && pipes[i][j] != '\0')
			j++;
		name = ft_substr(pipes[i], 0, j);
		args = ft_strdup(pipes[i] + j);
		new = new_elem(name, args);
		if (!new)
			exit(1);
		elem_add_back(&all->cmd, new);
		free(pipes[i]);
	}
	free(pipes);
	return (0);
}
