#include "minishell.h"

int		sort_ft(char **buf)
{
	if (ft_strncmp(buf[0], "ls", ft_strlen(buf[0])) == 0)
		printf("ls-----\n");
	else
		printf("diff-----\n");
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int		ret;
	char	*current_path;
	char	*line;
	char	tmp[MAXSIZE];
	int		i;
	char	**buf;
	struct	termios term;
	
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	(void)argv;
	line = NULL;
	ret = argc;
	i = -1;

	/*while (env[++i])
	{
			write(1, env[i], ft_strlen(env[i]));
			write(STDOUT, "\n", 1);
	}*/
	while (TRUE)
	{
		//ft_putstr_fd(getcwd(current_path, MAXSIZE), STDIN);
		ft_putstr_fd("sh> ", STDOUT);
		ret = read(STDIN, tmp, BUFFER_SIZE);
		write(STDOUT, tmp, ret);
	}
	write(STDOUT, "\n", 1);
	return (0);
}