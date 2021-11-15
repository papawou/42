GCC := gcc

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    GCC_FLAGS = -Wall -Werror -Wextra -g -fdiagnostics-color=always
else
    GCC_FLAGS = -Wall -Werror -Wextra
endif
NAME := exe.out

INC_DIR := ./
OBJ_DIR := ./obj
SRC_DIR := ./src

SRC := format_flags.c  format_types.c  ft_printf.c  ft_utils.c  parser_flags.c  test.c
OBJ := ${SRC:.c=.o}
OBJS := ${addprefix ${OBJ_DIR}/,${OBJ}}

all : $(NAME)

$(NAME) : ${OBJS}
	$(GCC) $(GCC_FLAGS) $^ -o $@ -I${INC_DIR}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	$(GCC) $(GCC_FLAGS) -c $< -o $@ -I${INC_DIR}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re