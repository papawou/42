#ifndef STACK_CMD_H
#define STACK_CMD_H

#include "stack.h"

void cmd_swap(t_stack *stack);
void cmd_push(t_stack *src, t_stack *dst);
void cmd_rotate(t_stack *stack);
void cmd_rrotate(t_stack *stack);

#endif