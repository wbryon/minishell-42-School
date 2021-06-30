SRCS	=	minishell.c\
			history.c\
			parser.c\
			shell_prompt.c\
			parser2.c\
			init.c\
			check_syntax.c

NAME	= minishell

OBJS	=	${SRCS:.c=.o}

INCL	=	minishell.h\
			libft/libft.h

LIBFT	=	libft/libft.a

CC		=	gcc
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(INCL) libft/*.c
			$(CC) -ltermcap $(OBJS) $(LIBFT) -o $(NAME)

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