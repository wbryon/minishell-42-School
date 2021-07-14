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
# include <readline/readline.h>
# include <readline/history.h>
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

typedef struct s_cmd
{
	char			**args;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_semicolon
{
	int		sq_flag;
	int		dq_flag;
	int		count;
	int		s_quotes;
	int		d_quotes;
	char	**semicolon;
}			t_semicolon;

typedef struct s_all
{
	char			**env;
	t_cmd			cmd;
	t_semicolon		s_c;
	struct termios	params;
	char			*command_buf;
}					t_all;

void		init_vars(t_all *all);
char		**copy_env(char **env, char *str);
void		get_history(char *buf, t_all *all);
int			init_termcap_functions(t_all *all);
void		hist_move_to_end(t_all *all);
void		write_line_to_history(char *buf, t_all *all);
int			check_string(char *buf, t_all *all);
int			if_up_down_keys(t_all *all, char *buf);
int			if_backspace(t_all *all, char *buf);
int			ctrl_d(t_all *all);
char		*parser(t_all *all);
void		check_d_quotes(t_all *all);
void		check_s_quotes(t_all *all);
int			check_quotes(t_all *all);
void		parse_semicolon(t_all *all, int *i);
char		*parse_quotes(char *str, int *i);
t_cmd		*new_elem(char **args);
void		elem_add_back(t_cmd **cmds, t_cmd *new);
void		free_list(t_cmd *list);
void		exec_builtin(t_all *all);
void		free_array(char **array);
#endif