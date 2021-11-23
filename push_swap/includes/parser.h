#ifndef PARSER_H
# define PARSER_H

#include <sys/types.h>

#include "stack.h"

t_stack *parse_args(char *args[], size_t len);

#endif