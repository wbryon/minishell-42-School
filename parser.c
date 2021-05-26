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
			tmp = parse_quotes(tmp, &i);
	}
	printf("|final=%s|\n", tmp);
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
		if (str[*i] == '\'')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	printf("|*i=%d|  |j=%d|  |tmp=%s|\n", *i, j, tmp);
	tmp2 = ft_substr(str, j + 1, *i - (j + 1));
	printf("|tmp2=%s|\n", tmp2);
	tmp3 = ft_strdup(str + *i + 1);
	printf("|tmp3=%s|\n", tmp);
	tmp = ft_strjoin(tmp, tmp2);
	printf("|tmp+tmp2=%s|\n", tmp);
	tmp = ft_strjoin(tmp, tmp3);
	printf("|tmp+tmp3=%s|\n", tmp);
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

static void	if_general(char **str, int *state)
{
	if (**str == '\\' && *(*str + 1) != '\0')
		*str = *str + 1;
	else if (**str == '\'')
		*state = S_QUOTE;
	else if (**str == '\"')
		*state = D_QUOTE;
}

int	validate_quotes(char *str)
{
	int	state;

	state = GENERAL;
	while (*str)
	{
		if (state == GENERAL)
			if_general(&str, &state);
		else if (state == S_QUOTE && *str == '\'')
			state = GENERAL;
		else if (state == D_QUOTE)
		{
			if (*str == '\\' && *(str + 1) != '\0')
				str++;
			else if (*str == '\"')
				state = GENERAL;
		}
		if (*str != '\0')
			str++;
	}
	if (state != GENERAL)
		return (-1);
	return (0);
}