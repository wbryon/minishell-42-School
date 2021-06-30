#include "minishell.h"

static char	*ft_slash(char *str, int *i)
{
	char	*tmp;
	char	*tmp2;
	if (str[*i + 1] && str[*i + 1] == '\'')
	{
		tmp = ft_substr(str, 0, *i);
		tmp2 = ft_strdup(str + *i + 1);
		tmp = ft_strjoin(tmp, tmp2);
		free(str);
		++(*i);
		return (tmp);
	}
	else
	{
		tmp = ft_strdup(str);
		free(str);
	}
	return (tmp);
}

static char	*ft_squote(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	while (str[++(*i)])
	{
		if (str[*i] == '\'')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	//printf("|tmp=%s|\n", tmp);
	tmp2 = ft_substr(str, j + 1, *i - (j + 1));
	//printf("|tmp2=%s|\n", tmp2);
	tmp3 = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	//printf("|tmp+tmp2=%s|\n", tmp);
	free(tmp2);
	free(tmp3);
	tmp3 = ft_strdup(str + *i + 1);
	//printf("|tmp3=%s|\n", tmp3);
	tmp2 = tmp;
	tmp = ft_strjoin(tmp, tmp3);
	//printf("|tmp+tmp3=%s|\n", tmp);
	free(tmp2);
	free(tmp3);
	free(str);
	*i -= 2;
	return (tmp);
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
	int		z;
	int		len;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	len = 0;
	while (str[++(*i)])
	{
		if (!ft_iskey(str[*i]))
			break;
	}
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	int k = -1;
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

static char	*ft_dquote(char *str, int *i, t_all *all)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
//	printf("i: %d\n", *i);
	while (str[++(*i)])
	{
		if (str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$' || \
		str[*i + 1] == '\\'))
			str = ft_slash(str, i);
		if (str[*i] == '$')
			str = ft_dollar(str, i, all);
		if (str[*i] == '\"')
			break;
	}
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

static	char *ft_semicolon(char *str, int *i, t_all *all)
{
	(void)str;
	(void)i;
	printf("sc: %d\n", all->s_c.count);
//	all->s_c.semicolon[all->s_c.count] = ft_substr(str, 0, j);
	all->s_c.count++;
	printf("sc: %d\n", all->s_c.count);
	return (str);
}

char	*parser2(t_all *all)
{
	int		i;
	char	*str;

	str = ft_strdup(all->command_buf);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			str = ft_squote(str, &i);
		if (str[i] == '\"')
			str = ft_dquote(str, &i, all);
		if (str[i] == '\\')
			str = ft_slash(str, &i);
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
