#include "minishell.h"
char	*parser(t_all *all)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strdup(all->history->current);
	while (tmp[++i])
	{
		if (tmp[i] == '\'')
		{
			if (tmp[i - 1] && tmp[i - 1] == '\\')
				continue ;
			else
				tmp = parse_quotes(tmp, &i);				
		}
	}
	return (tmp);
}

char	*parse_quotes(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	tmp = NULL;
	while (str[++(*i)] != '\0')
	{
		if (str[*i] == '\'' && str[*i - 1] == '\'')
		{
			tmp = ft_strdup(str + *i);
			*i = -1;
			free(str);
			return (tmp);
		}
		else if (str[*i] == '\'' && str[*i - 1] == '\\')
			*i += 1;
		if (str[*i] == '\'')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - (j + 1));
	tmp3 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp2);
	tmp = ft_strjoin(tmp, tmp3);
	free(tmp2);
	free(tmp3);
	return (tmp);
}

void	parse_semicolon(t_all *all, int *i)
{
	int	j;

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