SRCS		= ./srcs/ft_putchar.c ./srcs/ft_strcmp.c ./srcs/ft_swap.c \
			  ./srcs/ft_putstr.c ./srcs/ft_strlen.c

HEADERS		= ./includes/

FOlDER		= ./srcs/

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}
			
${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
