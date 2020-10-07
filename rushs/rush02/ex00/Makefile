SRCS	=	main.c ft_power.c ft_strlen.c getnumbers.c ft_putchar.c ft_strncpy init_struct.c params.c ft_atoi.c ft_putstr.c ft_strrev.c init_numbers.c read.c display.c ft_itoa.c ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
