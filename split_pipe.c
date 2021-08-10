#include "minishell.h"

char	**split_redirect(t_all *all, char *str)
{
	char	*ptr;
	char	*tmp;
	char	**args;

	tmp = ft_strdup(str);
	if (ft_strchr(tmp, '>'))
	{
		ptr = ft_strchr(tmp, '>');
		if (*(ptr + 1) == '<')
			ft_putstr_fd("syntax error near unexpected token `<'\n", STDOUT);
		if (*(ptr + 1) == '>')
		{
			if (ft_strchr(ptr, '<'))
				ft_putstr_fd("syntax error near unexpected token\n", STDOUT);
			all->cmd.flag_d_red_out = 1;
			args = ft_splitset(tmp, " >");
		}
		else
		{
			all->cmd.flag_red_out = 1;
			args = ft_splitset(tmp, " >");
		}
	}
	else if (ft_strchr(tmp, '<'))
	{
		ptr = ft_strchr(tmp, '<');
		if (*(ptr + 1) == '<')
		{
			if (ft_strchr(ptr, '>') || ft_strchr(ptr, '<'))
				ft_putstr_fd("syntax error near unexpected token\n", STDOUT);
			all->cmd.flag_d_red_out = 1;
			args = ft_splitset(tmp, " <");
		}
		else
		{
			all->cmd.flag_red_out = 1;
			args = ft_splitset(tmp, " <");
		}
	}
	else
		args = ft_split(tmp, ' ');
	free(tmp);
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
