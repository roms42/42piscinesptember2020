SRCS		= main.c ft_atoi.c ft_putnbr.c ops.c

OBJS		= ${SRCS:.c=.o}

NAME		= do-op

HEADERS 	= ./includes/

CFLAGS		= -Wall -Wextra -Werror

CC			= gcc

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
