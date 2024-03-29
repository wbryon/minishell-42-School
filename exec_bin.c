#include "minishell.h"

static void	get_path(t_all *all, char **path, char **splitted)
{
	int				i;
	char			*tmp;
	DIR				*dir;
	struct dirent	*entity;

	i = -1;
	while (splitted[++i])
	{
		dir = opendir(splitted[i]);
		if (!dir)
			return ;
		entity = readdir(dir);
		while (entity)
		{
			if (!ft_strcmp(entity->d_name, all->cmd.args[0]))
			{
				*path = ft_strjoin(splitted[i], "/");
				tmp = *path;
				*path = ft_strjoin(*path, all->cmd.args[0]);
				free(tmp);
			}
			entity = readdir(dir);
		}
		closedir(dir);
	}
}

static char	*try_path(t_all *all)
{
	char	*path;
	char	**splitted;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	splitted = ft_split(path, ':');
	if (!splitted)
		return (NULL);
	path = NULL;
	get_path(all, &path, splitted);
	free_array(splitted);
	return (path);
}

int	exec_bin(t_all *all)
{
	char	*path;
	pid_t	pid;

	if (!all->cmd.args[0])
		return (5);
	if (ft_strchr("./", all->cmd.args[0][0]))
		path = ft_strdup(all->cmd.args[0]);
	else
		path = try_path(all);
	if (path)
	{
		pid = fork();
		if (pid == -1)
			return (4);
		if (pid == 0)
			execve(path, all->cmd.args, all->env);
		else
			wait(NULL);
	}
	return (0);
}
