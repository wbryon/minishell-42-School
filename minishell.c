#include "minishell.h"

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
	char	*tmp;
	char	*line;
	char	buf[MAXSIZE];
	int		i;
	t_all	all;
	char	*term_name;
	struct	termios term;

	(void)argv;
	(void)argc;
	ft_bzero(&all, sizeof(all));
	line = ft_strdup("");
	tmp = NULL;
	i = -1;
	all.env = (char **)malloc(sizeof(envp));
	while (envp[++i])
		all.env[i] = ft_strdup(envp[i]);
	term_name = "xterm-256color";
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);
	while (strcmp(buf, "\4"))
	{
		ft_putstr_fd("sh> ", STDOUT);
		tputs(save_cursor, 1, ft_putchar);
		while (ft_strcmp(buf, "\n"))
		{
			ret = read(STDIN, &buf, BUFFER_SIZE);
			buf[ret] = '\0';
			if (ft_isprint(*buf))
			{
				read_line(buf, &all);
				write(STDOUT, buf, ret);
			}
			else if (!ft_strcmp(buf, "\e[A"))//CURSOR UP
			{
				tputs(save_cursor, 1, ft_putchar);
				tputs(tgetstr("cd", 0), 1, ft_putchar);
				write(STDOUT, "previous", 8);
			}
			else if (!ft_strcmp(buf, "\e[B"))//CURSOR DOWN
			{
				tputs(save_cursor, 1, ft_putchar);
				tputs(tgetstr("cd", 0), 1, ft_putchar);
				write(STDOUT, "next", 4);
			}
			else if (!ft_strcmp(buf, "\177"))//BACKSPACE
			{
				int len = (int)ft_strlen(line);
				if (len > 0)
				{
					tputs(cursor_left, 1, ft_putchar);
					tputs(delete_character, 1, ft_putchar);
					line[len - 1] = '\0';
				}
			}
			else if (!ft_strcmp(buf, "\011"))//TAB
				tputs(cursor_normal, 1, ft_putchar);
		}
	}
	write(STDOUT, "\n", 1);
	return (0);
}