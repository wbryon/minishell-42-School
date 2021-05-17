#include "minishell.h"

int		ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	main(int argc, char **argv, char **env)
{
	int		ret;
	char	tmp[MAXSIZE];
	char	*term_name;
	struct	termios term;
	struct	winsize win;

	ioctl(1, TIOCGWINSZ, &win);
	term_name = "xterm-256color";
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, term_name);
	
	while (strcmp(tmp, "\4"))
	{
		tputs(save_cursor, 1, ft_putchar);
		do
		{			
			ret = read(STDIN, tmp, BUFFER_SIZE);
			tmp[ret] = 0;
			if (!strcmp(tmp, "\e[A"))
			{
				tputs(restore_cursor, 1, ft_putchar);
				tputs(tgetstr("dc", NULL), 1, ft_putchar);
				write(STDOUT, "previous", 8);
			}
			else if (!strcmp(tmp, "\e[B"))
			{
				tputs(restore_cursor, 1, ft_putchar);
				tputs(tgetstr("dc", NULL), 1, ft_putchar);
				write(STDOUT, "next", 4);
			}
			else if (!strcmp(tmp, "\177"))
			{
				tputs(cursor_left, 1, ft_putchar);
				tputs(tgetstr("dc", NULL), 1, ft_putchar);
			}
			else
				write(STDOUT, tmp, ret);
		} while (strcmp(tmp, "\n") && strcmp(tmp, "\4"));
	}
	write(STDOUT, "\n", 1);
	return (0);
}