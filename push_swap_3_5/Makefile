SRCS = push_swap.c push_swap_utils.c push_swap_utils2.c ft_split.c push_swap_utils3.c push_swap_utils4.c push_swap_no_write.c push_swap_hc.c push_swap_commands.c push_swap_commands2.c push_swap_commands3.c
OBJS = ${SRCS:.c=.o}
CC    = gcc
CFLAGS	= -Wextra -Wall -Werror
NAME	= push_swap
.c.o:		&{CC} &{CFLAGS} -c -o $@ $<

${NAME} : ${OBJS}
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all:  ${NAME}

clean:
	 rm -f ${OBJS}
	
fclean :	clean
	rm -f ${NAME}

re : fclean all clean

leaks: 
	leaks -atExit -- ./pipex

.Phony: all bonus clean fclean re
