#include "minishell.h"

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

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	exec_builtin(t_all *all)
{
	if (!ft_strcmp(all->cmd.args[0], "echo"))
		exec_echo(all);
	else if (!ft_strcmp(all->cmd.args[0], "env"))
		exec_env(all);
	if (!ft_strcmp(all->cmd.args[0], "pwd"))
		exec_pwd();
	else if (!ft_strcmp(all->cmd.args[0], "export"))
		exec_export(all);
	else if (!ft_strcmp(all->cmd.args[0], "unset"))
		exec_unset(all);
	else if (!ft_strcmp(all->cmd.args[0], "cd"))
		exec_cd(all);
	else if (!ft_strcmp(all->cmd.args[0], "exit"))
		exec_exit(all);
}
