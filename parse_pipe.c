#include "minishell.h"

char	**split_redirect(t_all *all, char *str)
{
	char	*tmp;
	char	**args;

	args = NULL;
	tmp = ft_strdup(str);
	if (ft_strchr(tmp, '>'))
	split_redirect_out(all, tmp);
	else if (ft_strchr(tmp, '<'))
	{
		tmp = ft_strchr(tmp, '<');
		if (*(tmp + 1) == '<')
		{
			if (ft_strchr(tmp, '>') || ft_strchr(tmp, '<'))
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
	// free(tmp);
	return (args);
}

int	parse_pipe(t_all *all, char *str)
{
	int		i;
	char	**cmds;

	if (str[0] == '|' || str[ft_strlen(str) - 1] == '|')
		ft_putstr_fd("syntax error near unexpected token `|'\n", STDOUT);
	cmds = ft_split(str, '|');
	i = -1;
	while (cmds[++i])
	{
		cmds[i] = ft_strtrim(cmds[i], " ");
		if (cmds[i][0] == '\0')
			ft_putstr_fd("syntax error near unexpected token `|'\n", STDOUT);
		all->token = new_pipe(cmds[i]);
		if (!all->token)
			exit(1);
		pipe_add_back(&all->begin, all->token);
		free(cmds[i]);
	}
	return (0);
}