#include "minishell.h"

char	**find_key(char **environ, char *key)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (key[len] && key[len] != '=')
		len++;
	while (environ[++i])
	{
		if (!ft_strncmp(environ[i], key, len)
		&& (environ[i][len] == '=' || environ[i][len] == '\0'))
			return (&environ[i]);
	}
	return (NULL);
}