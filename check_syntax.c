#include "minishell.h"

void	check_s_quotes(t_all *all)
{
	int	i;
	int	s_quotes;

	i = -1;
	s_quotes = 0;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '\'')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
			{
				if (all->command.s_quotes && all->command.s_quotes % 2 != 0)
					all->command.s_quotes++;
				else
					continue ;
			}
			else
				all->command.s_quotes++;
		}
	}
}

void	check_d_quotes(t_all *all)
{
	int	i;

	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '"')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
			{
				if (all->command.d_quotes && all->command.d_quotes % 2 != 0)
					all->command.d_quotes++;
				else
					continue ;
			}
			else
				all->command.d_quotes++;
		}
	}
}
	
int	check_quotes(t_all *all)
{
	check_s_quotes(all);
	check_d_quotes(all);
	if (all->command.s_quotes % 2 != 0 || all->command.d_quotes % 2 != 0)
		return (1);
	return (0);
}

// static int	validate_if(t_all *all, t_token *token, t_token *previous_token)
// {
// 	if (((token->type == '>' || token->type == -2 || token->type == '<')
// 		&& (previous_token->type != -1 || token->next == NULL || token->next->type != -1))
// 		|| (token->type == '|' && (previous_token->type != -1 || token->next == NULL || token->next->type != -1))
// 		|| (token->type == ';' && previous_token->type != -1))
// 	{
// 		print_error_unexpctd_near_tok(all, token);
// 		return (-1);
// 	}
// 	return (0);
// }