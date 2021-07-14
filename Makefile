SRCS	=	minishell.c\
			init_vars.c\
			check_syntax.c\
			parser.c \
			new_elem.c \
			exec_builtins.c

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