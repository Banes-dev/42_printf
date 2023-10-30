CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

FUNC =	ft_printf.c ft_printf_utils.c

OBJS = ${FUNC:.c=.o} 


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar -rsc ${NAME} ${OBJS}

all: 	${NAME}

clean:	
		rm -f ${OBJSALL}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
