#ifndef PARSER_H
# define PARSER_H

#include <sys/types.h>

#include "stack/stack.h"

t_stack *parse_args(char *args[], size_t len);
t_stack *parse_int_args(int args[], size_t len);

#endif