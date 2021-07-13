#include "minishell.h"

void	execute_echo(char **av)
{
	int i;
	int new_line;

	new_line = 1;
	i = 1;
	if (av[1])
	{
		if (!ft_strcmp(av[i + 1], "-n"))
		{
			new_line = 0;
			i++;
		}
		while (av[++i])
		{
			write(1, av[i], ft_strlen(av[i]));
			if (av[i + 1])
				write(1, " ", 1);
		}
	}
	if (new_line)
		write(1, "\n", 1);
}

void    exec_env(char **av, char **env)
{
	int i;

	i = -1;
	if (av[2])
	{
		printf("env: %s: No such file or directory\n", av[2]);
		return ;
	}
	if (env)
	{
		while (env[++i])
		{
			printf("%s\n", env[i]);
		}
	}
}

void    exec_pwd(void)
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

void    exec_export(char **av, char **env)
{
	int     i;
	char    **tmp_env;

	i = 1;
	while (av[i++])
	{
		tmp_env = copy_env(env, av[i]);
		free(env);
		env = tmp_env;
	}
	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
}

void    exec_unset()
{

}

void    exec_cd()
{

}

void    exec_exit()
{

}

int main(int ac, char **av, char **env)
{
	char	**new_env;

	new_env = copy_env(env, NULL);
	if (!ft_strcmp(av[1], "echo"))
		execute_echo(av);
	else if (!ft_strcmp(av[1], "env"))
		exec_env(av, new_env);
	else if (!ft_strcmp(av[1], "pwd"))
		exec_pwd();
	else if (!ft_strcmp(av[1], "export"))
		exec_export(av, new_env);
	else if (!ft_strcmp(av[1], "unset"))
		exec_unset();
	else if (!ft_strcmp(av[1], "cd"))
		exec_cd();
	else if (!ft_strcmp(av[1], "exit"))
		exec_exit();
	return (0);
}
