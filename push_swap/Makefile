NAME := push_swap

CC := gcc

DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CC_FLAGS := -Wall -Werror -Wextra -g -fdiagnostics-color=always
else
    CC_FLAGS := -Wall -Werror -Wextra
endif

INC_DIR := ./includes
SRC_DIR := ./src
OBJ_DIR := ./obj

SRC := bcktrack.c  game.c  main.c  parser.c  stack.c  stack_cmd.c  stack_hist.c  stack_swap.c  view.c
OBJ := ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${addprefix ${OBJ_DIR}/, ${OBJ}}
	${CC} ${CC_FLAGS} $^ -o $@ -I${INC_DIR}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	${CC} ${CC_FLAGS} -c $< -o $@ -I${INC_DIR}

clean :
	rm -rf ${OBJ_DIR}/*.o

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean re all