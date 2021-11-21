GCC := gcc
AR := ar
AR_FLAGS := rcs
DEBUG ?= 0
ifeq ($(DEBUG), 1)
    GCC_FLAGS = -g -fdiagnostics-color=always
else
    GCC_FLAGS = -Wall -Werror -Wextra
endif
NAME := libftprintf.a

INC_DIR := ./headers
OBJ_DIR := ./obj
SRC_DIR := ./src

SRC := format_flags.c  format_types.c  ft_printf.c  ft_utils.c  parser.c  t_flags.c
OBJ := ${SRC:.c=.o}
OBJS := ${addprefix ${OBJ_DIR}/,${OBJ}}

all : $(NAME)

$(NAME) : ${OBJS}
	$(AR) $(AR_FLAGS) $@ $^

bonus : ${OBJS}
	$(AR) $(AR_FLAGS) ${NAME} $^

exe.out : ${OBJS} ./obj/test.o
	$(GCC) $(GCC_FLAGS) $^ -o $@ -I${INC_DIR}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	$(GCC) $(GCC_FLAGS) -c $< -o $@ -I${INC_DIR}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f $(NAME) exe.out bonus.a

re : fclean all

.PHONY : clean fclean re