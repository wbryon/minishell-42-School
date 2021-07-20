SRCS	=	minishell.c\
			init_vars.c\
			check_syntax.c\
			parser.c \
			new_elem.c \
			exec_builtin.c \
			builtins/exec_echo.c \
			builtins/exec_env.c \
			builtins/exec_pwd.c \
			builtins/exec_export.c \
			builtins/exec_unset.c \
			builtins/exec_cd.c \
			builtins/exec_exit.c \
			utils.c \
			exec_bin.c

NAME	= minishell

OBJS	=	${SRCS:.c=.o}

INCL	=	minishell.h\
			libft/libft.h

LIBFT	=	libft/libft.a

CC		=	gcc
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(INCL) libft/*.c
			$(CC) -ltermcap -lreadline $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):	
			make -C "libft"

clean:		
			$(RM) $(OBJS)
			make clean -C "libft"

fclean:		clean
			$(RM) $(NAME)
			make fclean -C "libft"

re:			fclean all

.PHONY:		all clean fclean re