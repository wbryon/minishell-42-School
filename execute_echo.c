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

int main(int ac, char **av)
{
    execute_echo(av);
    return (0);
}
