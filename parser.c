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
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	while (all->history->current[++(*i)])
	{
		if (all->history->current[*i] == '\'')
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