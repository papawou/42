GCC = gcc
GCC_FLAGS = -Wall -Werror -Wextra
NAME = exe.out

INC_DIR = ./headers
OBJ_DIR = ./obj
SRC_DIR = ./src

SRC = format_flags.c  format_types.c  ft_printf.c  ft_utils.c  parser_flags.c  test.c
OBJ = ${SRC=.c:.o}
OBJS = ${addprefix ${OBJ_DIR}, ${OBJ}}

all : $(NAME)

$(NAME) : ${OBJS}
	$(GCC) $(GCC_FLAGS) $^ -o $@ -I${INC_DIR}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	$(GCC) -c $< -o $@ -I${INC_DIR}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re