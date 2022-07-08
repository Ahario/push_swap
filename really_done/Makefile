SRCS = push_swap.c push_swap_utils.c push_swap_utils2.c ft_split.c push_swap_utils3.c push_swap_utils4.c\
		push_swap_no_write.c push_swap_hc.c push_swap_commands.c push_swap_commands2.c push_swap_commands3.c\
		push_swap_utils5.c push_swap_big.c push_swap_hc2.c push_swap_big2.c push_swap_utils6.c push_swap_utils7.c
OBJS = ${SRCS:.c=.o}
CC    = gcc
CFLAGS	= -Wextra -Wall -Werror -g
#CFLAGS += -g -fsanitize=address
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
