#include "minishell.h"

static char	*quote_substr(char *str, int j, int *i)
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
	*i -= 2;
	return (tmp);
}

static char	*ft_slash(t_all *all, char *str, int *i)
{
	char	*tmp;
	char	*tmp2;

	if (all->command.sq_flag == 0)
	{
		if (str[*i + 1])
		{
			all->command.slash_flag = 1;
			tmp = ft_substr(str, 0, *i);
			tmp2 = ft_strdup(str + *i + 1);
			tmp = ft_strjoin(tmp, tmp2);
			free(str);
			free(tmp2);
			++(*i);
			return (tmp);
		}
		else
		{
			printf("slash is odd\n");
			return (str);
		}
	}
	else
	{
		++(*i);
		tmp = ft_strdup(str);
		free(str);
		return (tmp);
	}
	return (tmp);
}

static char	*ft_squote(t_all *all, char *str, int *i)
{
	int	j;

	j = *i;
	all->command.sq_flag = 1;
	while (str[++(*i)])
	{
		if (str[*i] == '\'')
		{
			if (all->command.slash_flag == 1)
			{
				if (str[*i - 1] == '\'')
					all->command.sq_flag = 0;
				break ;
			}
			else
				break ;
		}
		else
			return (quote_substr(str, j, i));
		
	}
	return (quote_substr(str, j, i));
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
	int		z;
	int		len;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	k = -1;
	len = 0;
	while (str[++(*i)])
	{
		if (!ft_iskey(str[*i]))
			break;
	}
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	while (all->env[++k])
	{
		if (strstr(all->env[k], tmp))
		{
			z = 0;
			while (all->env[k][z] && all->env[k][z] != '=')
				z++;
			tmp2 = ft_substr(all->env[k], 0, z);
			if (!ft_strcmp(tmp, tmp2))
			{
				free(tmp2);
				break ;
			}
			free(tmp2);
		}
	}
	len = ft_strlen(tmp);
	tmp2 = ft_strdup(all->env[k] + z + 1);
	free(tmp);
	tmp = ft_substr(str, 0, j);
	tmp3 = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp3);
	tmp2 = ft_strdup(str + j + len + 1);
	tmp3 = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp3);
	free(str);
	return (tmp);
}

static char	*ft_dquote(t_all *all, char *str, int *i)
{
	int		j;

	j = *i;
	while (str[++(*i)])
	{
		if (str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$' || str[*i + 1] == '\\'))
			str = ft_slash(all, str, i);
		if (str[*i] == '$')
			str = ft_dollar(str, i, all);
		if (str[*i] == '\"')
			break;
	}
	return (quote_substr(str, j, i));
}

static	char *ft_semicolon(char *str, int *i, t_all *all)
{
	(void)str;
	(void)i;
	all->command.semicolon[all->command.count] = ft_substr(str, 0, *i);
	all->command.count++;
	return (str);
}

char	*parser2(t_all *all)
{
	int		i;
	char	*str;

	str = ft_strdup(all->history->current);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			str = ft_squote(all, str, &i);
		}
		if (str[i] == '\"')
			str = ft_dquote(all, str, &i);
		if (str[i] == '\\')
		{
			str = ft_slash(all, str, &i);
		}
		if (str[i] == '$')
			str = ft_dollar(str, &i, all);
		if (str[i] == ';')
			str = ft_semicolon(str, &i, all);
	}
	return (str);
}

/*int	preparser(char *str)
{
	while (str[++i])
		do something
}*/

void	parse_semicolon(t_all *all, int *i)
{
	int	j;

	j = *i;
	while (all->history->current[++(*i)])
	{
		if (all->history->current[*i] == ';')
		{
			all->command.semicolon[all->command.count] = ft_substr(all->history->current, 0, j);
			all->command.count++;
			break ;
		}
	}
}