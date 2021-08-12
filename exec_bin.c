#include "minishell.h"

static void	get_path(char *bin, char **path, char **splitted)
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
			if (!ft_strcmp(entity->d_name, bin))
			{
				*path = ft_strjoin(splitted[i], "/");
				tmp = *path;
				*path = ft_strjoin(*path, bin);
				free(tmp);
			}
			entity = readdir(dir);
		}
		closedir(dir);
	}
}

char	*try_path(char *bin)
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
	get_path(bin, &path, splitted);
	free_array(splitted);
	return (path);
}

int	exec_bin(t_all *all)
{
	(void)all;
	char	*path;
	pid_t	pid;

	if (!all->cmd->name)
		return (5);
	if (ft_strchr("./", all->cmd->name[0]))
		path = ft_strdup(all->cmd->name);
	else
		path = try_path(all->cmd->name);
	if (path)
	{
		pid = fork();
		if (pid == -1)
			return (4);
		// if (pid == 0)
			// execve(path, all->cmd->args, all->env);
		else
			wait(NULL);
	}
	return (0);
}
