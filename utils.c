#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	search_env(t_all *all, char *key)
{
	int	i;
	int	idx;

	idx = ft_strlen(key);
	i = -1;
	while (all->env[++i])
	{
		if (!ft_strncmp(all->env[i], key, idx) && \
			(all->env[i][idx] == '=' || \
			all->env[i][idx] == '\0'))
			return (i);
	}
	return (-1);
}

char	**copy_env(char **env, char *str)
{
	int		i;
	char	*new_env;
	char	**copy;

	new_env = ft_strdup(str);
	i = 0;
	while (env[i])
		i++;
	if (new_env)
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (env[++i])
		copy[i] = ft_strdup(env[i]);
	if (new_env)
		copy[i++] = ft_strdup(new_env);
	copy[i] = NULL;
	free(new_env);
	return (copy);
}
