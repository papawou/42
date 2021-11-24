#ifndef STACK_CMD_H
#define STACK_CMD_H

#include "stack.h"

typedef enum e_cmd
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_cmd
{
	enum e_cmd move;
	struct s_cmd *prev;
	unsigned int pos;
} t_cmd;

void cmd_swap(t_stack *stack);
void cmd_push(t_stack *src, t_stack *dst);
void cmd_rotate(t_stack *stack);
void cmd_rrotate(t_stack *stack);

#endif