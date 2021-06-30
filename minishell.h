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

enum e_token_type
{
	WHITESPACE = ' ',
	SEMICOLON = ';',
	QUOTE = '\'',
	DQUOTE = '\"',
	PIPE = '|',
	ESCAPESEQ = '\\',
	TAB = '\t',
	NEWLINE = '\n',
	MORE = '>',
	LESS = '<',
	DGREATER = -2,
	ZERO = 0,
	GENERAL = -1,
	TOKEN = -1,
};

typedef struct s_cmd
{
	char			*current;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct s_token
{
	char			*data;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct s_pipelist
{
	t_token				*token_list;
	struct s_pipelist	*next;
}						t_pipelist;

typedef struct s_lexer
{
	t_token	*token_list;
	int		num_of_tokens;
	int		char_type;
	t_token	*token;
	int		condition;
	int		size;
	int		j;
}				t_lexer;

typedef struct s_parse_utils
{
	t_pipelist	*pipelist;
	t_token		*current_token;
}				t_parse_utils;

typedef struct s_command
{
	int		count;
	int		slash_flag;
	int		sq_flag;
	int		dq_flag;
	int		s_quotes;
	int		d_quotes;
	char	**semicolon;
}			t_command;

typedef struct s_exec
{
	char	*cmd;
}			t_exec;

typedef struct s_all
{
	char			**env;
	t_history		*history;
	t_cmd			cmd;
	t_exec			exec;
	t_command		command;
	t_lexer			*lexer_buff;
	t_parse_utils	*parse_utils;
	struct termios	params;
}					t_all;

void		init_vars(t_all *all);
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
char		*parser(t_all *all);
char		*parser2(t_all *all);
void		check_d_quotes(t_all *all);
void		check_s_quotes(t_all *all);
int			check_quotes(t_all *all);
void		parse_semicolon(t_all *all, int *i);
char		*parse_quotes(char *str, int *i);
char		**find_key(char **environ, char *key);
int			prompt(t_all *all);
#endif