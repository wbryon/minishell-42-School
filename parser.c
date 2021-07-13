#include "minishell.h"

// static char	*trim_str(t_all *all, char *str, int j, int k, int z)
// {
// 	char	*tmp;
// 	char	*tmp2;
// 	char	*tmp3;

// 	tmp2 = ft_strdup(all->env[k] + z + 1);
// 	free(tmp);
// 	tmp = ft_substr(str, 0, j);
// 	tmp3 = tmp;
// 	tmp = ft_strjoin(tmp, tmp2);
// 	free(tmp2);
// 	free(tmp3);
// 	tmp2 = ft_strdup(str + j + ft_strlen(tmp) + 1);
// 	tmp3 = tmp;
// 	tmp = ft_strjoin(tmp, tmp2);
// 	free(tmp2);
// 	free(tmp3);
// 	free(str);
// 	return (tmp);
// }

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

static char	*ft_slash(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	j = *i;
	if (str[*i + 1] && (str[*i + 1] == '\'' || str[*i + 1] == '\"'
	|| str[*i + 1] == '\\' || str[*i + 1] == '$'))
	{
		tmp = ft_substr(str, 0, *i);
		tmp2 = ft_strdup(str + *i + 1);
		tmp = ft_strjoin(tmp, tmp2);
		free(str);
	}
	else
	{
		tmp = ft_substr(str, 0, j);
		tmp2 = ft_substr(str, j + 1, ft_strlen(str));
		tmp = ft_strjoin(tmp, tmp2);
		free(str);
	}
	return (tmp);
}

static char	*ft_squote(t_all *all, char *str, int *i)
{
	int	j;

	j = *i;
	while (str[++(*i)])
	{
		if (str[j + 1] == '\'')
			break ;
		if (str[*i] == '\'')
		{
			all->s_c.sq_flag = 1;
			break ;
		}
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
	int		z;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	k = -1;
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
		else
			return (tmp);
	}
	free(tmp);
	tmp2 = ft_strdup(all->env[k] + z + 1);
	tmp = ft_substr(str, 0, j);
	tmp3 = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(tmp2);
	free(tmp3);
	tmp2 = ft_strdup(str + j + ft_strlen(tmp) + 1);
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

	j = *i;
	while (str[++(*i)])
	{
		if (str[j + 1] == '\"')
			break ;
		if (str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$' || \
		str[*i + 1] == '\\'))
			str = ft_slash(str, i);
		if (str[*i] == '$')
			str = ft_dollar(str, i, all);
		if (str[*i] == '\"')
			break;
	}
	return (trim_quotes(str, j, i));
}

static	char *ft_semicolon(char *str, int *i, t_all *all)
{
	(void)str;
	(void)i;
	// printf("sc: %d\n", all->s_c.count);
//	all->s_c.semicolon[all->s_c.count] = ft_substr(str, 0, j);
	all->s_c.count++;
	// printf("sc: %d\n", all->s_c.count);
	return (str);
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
			all->s_c.sq_flag = 1;
			str = ft_squote(all, str, &i);
			continue ;
		}
		if (str[i] == '\"')
			str = ft_dquote(str, &i, all);
		if (str[i] == '\\')
		{
			str = ft_slash(str, &i);
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
