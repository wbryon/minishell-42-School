#include "minishell.h"

static char	*trim_quotes(char *str, int j, int *i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - (j + 1));
	tmp3 = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp3);
	tmp3 = ft_strdup(str + *i + 1);
	tmp2 = tmp;
	tmp = ft_strjoin(tmp, tmp3);
	free(tmp2);
	free(tmp3);
	free(str);
	*i = *i - 2;
	return (tmp);
}

static char	*ft_quote(char *str, int *i)
{
	int	j;

	j = *i;
	while (str[++(*i)])
	{
		if (str[j + 1] == '\'')
			break ;
		coder(str, i);
		if (str[*i] == '\'')
			break ;
	}
	return (trim_quotes(str, j, i));
}

static int	ft_iskey(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

static char	*ft_dollar(char *str, int *i, t_all *all)
{
	int		j;
	int		k;
	char	*tmp;

	j = *i;
	while (str[++(*i)])
	{
		if (!ft_iskey(str[*i]))
			break ;
	}
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	j = -1;
	while (all->env[++j])
	{
		if (strstr(all->env[j], tmp))
		{
			k = 0;
			while (all->env[j][k] && all->env[j][k] != '=')
				k++;
			if (!ft_strcmp(tmp, ft_substr(all->env[j], 0, k)))
				return (ft_strdup(all->env[j] + k + 1));
		}
	}
	return (tmp);
}

static char	*ft_dquote(char *str, int *i, t_all *all)
{
	int		j;

	j = *i;
	while (str[++(*i)])
	{
		if (str[j + 1] == '\"')
			break ;
		if (str[*i] == '$')
			str = ft_dollar(str, i, all);
		coder(str, i);
		if (str[*i] == '\"')
			break ;
	}
	return (trim_quotes(str, j, i));
}

char	*parser(t_all *all)
{
	int		i;
	char	*str;

	str = ft_strdup(all->command_buf);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			str = ft_quote(str, &i);
			continue ;
		}
		if (str[i] == '\"')
		{
			str = ft_dquote(str, &i, all);
		}
		if (str[i] == '$')
			str = ft_dollar(str, &i, all);
	}
	return (str);
}