#include "../minishell.h"

static void	go_home(t_all *all)
{
	char	*homedir;

	(void)all;
	homedir = getenv("HOME");
	if (homedir)
		chdir(homedir);
}

static void	go_back(t_all *all)
{
	char	*oldpwd;

	(void)all;
	oldpwd = getenv("OLDPWD");
	if (oldpwd)
	{
		ft_putendl_fd(oldpwd, 1);
		chdir(oldpwd);
	}
}

void	exec_cd(t_all *all)
{
	if (all->cmd.args[1])
	{
		if (!ft_strcmp(all->cmd.args[1], "~"))
			go_home(all);
		else if (!ft_strcmp(all->cmd.args[1], "-"))
			go_back(all);
		else
			chdir(all->cmd.args[1]);
	}
	else
		go_home(all);
}
