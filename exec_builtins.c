#include "minishell.h"

static void	execute_echo(t_all *all)
{
	int i;
	int new_line;

	new_line = 1;
	i = 0;
	if (all->cmd.args[i])
	{
		if (!ft_strcmp(all->cmd.args[i + 1], "-n"))
		{
			new_line = 0;
			i++;
		}
		while (all->cmd.args[++i])
		{
			write(1, all->cmd.args[i], ft_strlen(all->cmd.args[i]));
			if (all->cmd.args[i + 1])
				write(1, " ", 1);
		}
	}
	if (new_line)
		write(1, "\n", 1);
}

static void    exec_env(t_all *all)
{
	int i;

	i = -1;
	if (all->cmd.args[1])
	{
		printf("env: %s: No such file or directory\n", all->cmd.args[1]);
		return ;
	}
	if (all->env)
	{
		while (all->env[++i])
		{
			printf("%s\n", all->env[i]);
		}
	}
}

static void    exec_pwd(void)
{
	char    *pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 0);
	printf("%s\n", pwd);
	free(pwd);
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

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

static void    exec_export(t_all *all)
{
	int     i;
	char    **tmp_env;

	i = 0;
	while (all->cmd.args[++i])
	{
		tmp_env = copy_env(all->env, all->cmd.args[i]);
		free_array(all->env);
		all->env = tmp_env;
	}
}

static void    exec_unset()
{

}

static void    exec_cd()
{

}

static void    exec_exit()
{

}

void execute_cmd(t_all *all)
{
	(void)all;
	if (!ft_strcmp(all->cmd.args[0], "echo"))
		execute_echo(all);
	else if (!ft_strcmp(all->cmd.args[0], "env"))
		exec_env(all);
	if (!ft_strcmp(all->cmd.args[0], "pwd"))
		exec_pwd();
	else if (!ft_strcmp(all->cmd.args[0], "export"))
		exec_export(all);
	else if (!ft_strcmp(all->cmd.args[0], "unset"))
		exec_unset();
	else if (!ft_strcmp(all->cmd.args[0], "cd"))
		exec_cd();
	else if (!ft_strcmp(all->cmd.args[0], "exit"))
		exec_exit();
}
