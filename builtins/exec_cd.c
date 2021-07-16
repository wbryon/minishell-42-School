#include "../minishell.h"

static int	go_home(void)
{
	char	*homedir;

	homedir = getenv("HOME");
	if (homedir)
		return (chdir(homedir));
	return (-1);
}

static int	go_back(void)
{
	char	*oldpwd;

	oldpwd = getenv("OLDPWD");
	if (oldpwd)
	{
		ft_putendl_fd(oldpwd, 1);
		return (chdir(oldpwd));
	}
	return (-1);
}

static void	set_env(t_all *all, char *key, char *value)
{
	int		idx;
	char	*new;
	char	*tmp;

	idx = search_env(all, key);
	new = ft_strjoin(key, "=");
	tmp = new;
	new= ft_strjoin(new, value);
	free(tmp);
	tmp = all->env[idx];
	all->env[idx] = new;
	free(tmp);
}

static void	update_env(t_all *all, char *oldpwd)
{
	char	*new;

	if (oldpwd)
		set_env(all, "OLDPWD", oldpwd);
	new = NULL;
	new = getcwd(new, 0);
	if (new)
	{
		set_env(all, "PWD", new);
		free(new);
	}
}

void	exec_cd(t_all *all)
{
	int		ret;
	char	*oldpwd;

	oldpwd = NULL;
	oldpwd = getcwd(oldpwd, 0);
	if (all->cmd.args[1])
	{
		if (!ft_strcmp(all->cmd.args[1], "~"))
			ret = go_home();
		else if (!ft_strcmp(all->cmd.args[1], "-"))
			ret = go_back();
		else
			ret = chdir(all->cmd.args[1]);
	}
	else
		ret = go_home();
	if (ret == 0)
		update_env(all, oldpwd);
	// path = getenv("PWD");
	// setenv("OLDPWD", path, 1);
	// printf("path: %s\n", path);
}
