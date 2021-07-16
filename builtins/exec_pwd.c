#include "../minishell.h"

void	exec_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 0);
	if (pwd)
	{
		ft_putendl_fd(pwd, 1);
		free(pwd);
	}
}
