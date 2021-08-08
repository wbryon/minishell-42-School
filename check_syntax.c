#include "minishell.h"

int	check_quotes(t_all *all)
{
	int	i;

	i = -1;
	while (all->command_buf[++i])
	{
		if (all->command_buf[i] == '\'')
			all->parse.quotes++;
		else if (all->command_buf[i] == '"')
			all->parse.dquotes++;
	}
	if (all->parse.quotes % 2 != 0 || all->parse.dquotes % 2 != 0)
		return (1);
	return (0);
}

// void	check_dquotes(t_all *all)
// {
// 	int	i;

// 	i = -1;
// 	while (all->command_buf[++i])
// 	{
// 		if (all->command_buf[i] == '"')
// 			all->parse.dquotes++;
// 	}
// }
	
// int	quotes_checker(t_all *all)
// {
// 	check_squotes(all);
// 	check_dquotes(all);
// 	if (all->parse.quotes % 2 != 0 || all->parse.dquotes % 2 != 0)
// 		return (1);
// 	return (0);
// }