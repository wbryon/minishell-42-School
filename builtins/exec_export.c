#include "../minishell.h"

// static void	print_formatted_env(char *str)
// {
// 	ft_putstr_fd("declare -x ", 1);
// 	while (*str && *str != '=')
// 		write(1, str++, 1);
// 	if (*str == '=')
// 	{
// 		ft_putstr_fd("=\"", 1);
// 		while (*(++str))
// 			write(1, str, 1);
// 		ft_putstr_fd("\"", 1);
// 	}
// 	write(1, "\n", 1);
// }

// static void	swap_env(char **str1, char **str2)
// {
// 	char	*tmp;

// 	tmp = *str1;
// 	*str1 = *str2;
// 	*str2 = tmp;
// }

// static char	**sort_env(char **env)
// {
// 	int	i;
// 	int	j;
// 	int	len;

// 	i = 0;
// 	while (env[i])
// 		i++;
// 	len = i;
// 	i = -1;
// 	while (++i < len)
// 	{
// 		j = -1;
// 		while (++j < len - i - 1)
// 			if (ft_strcmp(env[j], env[j + 1]) > 0)
// 				swap_env(&env[j], &env[j + 1]);
// 	}
// 	return (env);
// }

// static int	print_env(t_all *all)
// {
// 	int		i;
// 	char	**copy;

// 	copy = copy_env(all->env, NULL);
// 	if (copy)
// 	{
// 		copy = sort_env(copy);
// 		i = -1;
// 		while (copy[++i])
// 			print_formatted_env(copy[i]);
// 		free_array(copy);
// 	}
// 	return (0);
// }

int	exec_export(t_all *all)
{
	(void)all;
	// int		i;
	// char	**copy;

	// if (!all->cmd->args[1])
	// 	return (print_env(all));
	// i = 0;
	// while (all->cmd->args[++i])
	// {
	// 	copy = copy_env(all->env, all->cmd->args[i]);
	// 	free_array(all->env);
	// 	all->env = copy;
	// }
	return (0);
}
