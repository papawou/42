CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJS = ${addprefix ${SRC_DIR}, ${SRCS:.c=.o}}

H_DIR = ./includes/
HEADERS = ft.h


TARGET = libft.a

all : $(TARGET)

$(TARGET) : ${OBJS} ./includes/ft.h
	ar $^ -o $@

%.o : %.c 
	gcc $(CFLAGS) -o $@ -c $<

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re