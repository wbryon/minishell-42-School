#include "minishell.h"
int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int		sort_ft(char **buf)
{
	if (ft_strncmp(buf[0], "ls", ft_strlen(buf[0])) == 0)
		printf("ls-----\n");
	else
		printf("diff-----\n");
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		ret;
	char	*current_path;
	char	*tmp;
	char	*line;
	char	buf[MAXSIZE];
	int		i;
	char	**var_env;
	char	*term_name;
	struct	termios term;

	(void)argv;
	line = ft_strdup("");
	tmp = NULL;
	i = -1;
	while (envp[++i])
		i++;
	var_env = (char **)malloc(sizeof(char) * i);
	i = -1;
	while (envp[++i])
	{
		var_env[i] = (char *)malloc(sizeof(char) * ft_strlen(envp[i]));
		var_env[i] = envp[i];
	}
	term_name = "xterm-256color";
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);
	ft_putstr_fd("sh> ", STDOUT);
	while (strcmp(buf, "\n") && strcmp(buf, "\4"))
	{
		tputs(save_cursor, 1, ft_putchar);
		ret = read(STDIN, &buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (!strcmp(buf, "\e[A"))
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tgetstr("dc", NULL), 1, ft_putchar);
			write(STDOUT, "previous", 8);
		}
		else if (!strcmp(buf, "\e[B"))
		{
			tputs(restore_cursor, 1, ft_putchar);
			tputs(tgetstr("dc", NULL), 1, ft_putchar);
			write(STDOUT, "next", 4);
		}
		else if (!strcmp(buf, "\177"))
		{
			tputs(cursor_left, 1, ft_putchar);
			tputs(tgetstr("dc", NULL), 1, ft_putchar);
		}
		else
		{
			write(STDOUT, buf, ret);
			{
				tmp = line;
				line = ft_strjoin(line, buf);
				free(tmp);
			}
		}
	}
	write(STDOUT, "\n", 1);
	return (0);
}