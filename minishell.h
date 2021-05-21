#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <string.h>
# include <dirent.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include "libft/libft.h"

# define MAXSIZE		1024
# define BUFFER_SIZE    32

# define FALSE			0
# define TRUE			1

# define ERROR			-1
# define SUCCESS 		1

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

# define SYNTAX_ERROR	"Syntax error: near unexpected token!"
# define QUOTE_ERROR 	"The number of quotes is odd!"
# define MALLOC_ERROR 	"Memory malloc fail!"
# define PIPE_ERROR 	"Pipe function is failed!"
# define FORK_ERROR 	"Fork function is failed!"

typedef struct s_history
{
	char				*current;
	char				*prime;
	struct s_history	*next;
	struct s_history	*prev;

}						t_history;

typedef struct s_all
{
	char			**env;
	t_history		*history;
	struct termios	params;
}					t_all;

void		get_history(char *buf, t_all *all);
int			init_termcap_functions(t_all *all);
t_history	*init_history_list(char *content);
void		add_line_to_history(t_history **lst, t_history *new);
void		hist_move_to_end(t_all *all);
void		write_line_to_history(char *buf, t_all *all);
int			check_string(char *buf, t_all *all);
int			if_up_down_keys(t_all *all, char *buf);
int			if_backspace(t_all *all, char *buf);
int			ctrl_d(t_all *all);

#endif