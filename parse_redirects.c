#include "minishell.h"

char	**parse_redirect_out(t_all *all, char *str)
{
	char	**args;
	char	*ptr;

	args = NULL;
	ptr = ft_strchr(str, '>');
	if (ft_strchr(ptr, '<'))
		ft_putstr_fd("syntax error near unexpected token `<'\n", STDOUT);
	if (ft_strncmp(ptr, ">>", 2))
		ft_putstr_fd("syntax error near unexpected token `>'\n", STDOUT);
	// {
	// 	while (++(*ptr) != '>')
	// 		if (!ft_isalnum(*ptr))
	// 			ft_putstr_fd("syntax error near unexpected token `>'\n", STDOUT);
	// 	all->cmd.flag_d_red_out = 1;
	// 	args = ft_splitset(str, " >");
	// }
	else
	{
		all->cmd.flag_red_out = 1;
		args = ft_splitset(str, " >");
	}
	free(str);
	return (args);
}