#include "minishell.h"
char	*parser(t_all *all)
{
	int		i;

	i = -1;
	while (all->history->current[++i])
	{
		if (all->history->current[i] == '\'')
			all->history->current = parse_quotes(all, &i);
	}
	return (parse_quotes(all, &i));
}

char	*parse_quotes(t_all *all, int *i)
{
	int		j;
	int		count;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	count = -1;
	while (all->history->current[++count] != '\0')
	{
		if (all->history->current[count] == '\'')
			break ;
	}
	tmp = ft_substr(all->history->current, 0, j);
	tmp2 = ft_substr(all->history->current, j + 1, *i - j - 1);
	tmp3 = ft_strdup(all->history->current + *i + 1);
	tmp = ft_strjoin(tmp, tmp2);
	tmp = ft_strjoin(tmp, tmp3);
	free(tmp2);
	free(tmp3);
	return (tmp);
}

void	parse_semicolon(t_all *all, int *i)
{
	int		j;

	j = *i;
	while (all->history->current[++(*i)])
	{
		if (all->history->current[*i] == ';')
		{
			all->s_c.semicolon[all->s_c.count] = ft_substr(all->history->current, 0, j);
			all->s_c.count++;
			break ;
		}
	}
}

int	check_quotes(t_all *all)
{
	int		i;

	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '\'')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
				i++;
			all->s_c.s_quotes++;
		}
	}
	i = -1;
	while (all->history->current[++i] != '\0')
	{
		if (all->history->current[i] == '\'')
		{
			if (all->history->current[i - 1] && all->history->current[i - 1] == '\\')
				i++;
			all->s_c.d_quotes++;
		}
	}
	if (all->s_c.s_quotes % 2 != 0)
		return (1);
	return (0);
}