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

static void	print_formatted_env(char *str)
{
	ft_putstr_fd("declare -x ", 1);
	while (*str && *str != '=')
		write(1, str++, 1);
	if (*str == '=')
	{
		ft_putstr_fd("=\"", 1);
		while (*(++str))
			write(1, str, 1);
		ft_putstr_fd("\"", 1);
	}
	write(1, "\n", 1);
}

static void	swap_env(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

static char **sort_env(char **env)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (env[i])
		i++;
	len = i;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len - i - 1)
			if (ft_strcmp(env[j], env[j + 1]) > 0)
				swap_env(&env[j], &env[j + 1]);
	}
	return (env);
}

static int	print_env(t_all *all)
{
	int	i;
	char	**copy;

	copy = copy_env(all->env, NULL);
	copy = sort_env(copy);
	i = -1;
	while (copy[++i])
		print_formatted_env(copy[i]);
	free_array(copy);
	return (0);
}

static int	exec_export(t_all *all)
{
	int     i;
	char    **tmp_env;

	if (!all->cmd.args[1])
		return (print_env(all));
	i = 0;
	while (all->cmd.args[++i])
	{
		tmp_env = copy_env(all->env, all->cmd.args[i]);
		free_array(all->env);
		all->env = tmp_env;
	}
	return (0);
}

static void	delete_env(t_all *all, int target)
{
	int		i;
	char	*tmp;

	tmp = all->env[target];
	i = 0;
	while (all->env[i])
		i++;
	all->env[target] = all->env[i - 1];
	all->env[i - 1] = NULL;
	free(tmp);
}

static void	unset_env(t_all *all, char *env)
{
	int	i;
	int	idx;

	idx = ft_strlen(env);
	i = -1;
	while (all->env[++i])
	{
		if (!ft_strncmp(all->env[i], env, idx) && \
			(all->env[i][idx] == '=' || \
			all->env[i][idx] == '\0'))
			delete_env(all, i);
	}
}

static void    exec_unset(t_all *all)
{
	int	i;

	i = 0;
	while (all->cmd.args[++i])
		unset_env(all, all->cmd.args[i]);
}

static void    exec_cd(t_all *all)
{
	(void)all;
}

static void    exec_exit(t_all *all)
{
	(void)all;
	exit(0);
}

void exec_builtin(t_all *all)
{
	if (!ft_strcmp(all->cmd.args[0], "echo"))
		execute_echo(all);
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
