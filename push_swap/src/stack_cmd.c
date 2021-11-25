#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"
#include "stack_swap.h"
#include "stack_cmd.h"
#include "game.h"

static bool cmd_swap(t_stack *stack)
{
	if (stack->size <= 1)
		return false;

	swap(stack->head, stack->head->prev);
	
	return true;
}

static bool cmd_push(t_stack *src, t_stack *dst)
{
	t_stack_elem *elem;

	if (!src->head)
		return false;
	
	elem = src->head;
	stack_remove(elem);
	stack_push(dst, elem);
	
	return true;
}

static bool cmd_rotate(t_stack *stack) //if stack->size == 2 same as swap
{
	t_stack_elem *head;

	if (stack->size <= 1)
		return false;

	head = stack->head;
	stack_remove(head);
	stack_rpush(stack, head);

	return true;
}

static bool cmd_rrotate(t_stack *stack)
{
	t_stack_elem *tail;

	if (stack->size <= 1) //if stack->size == 2 same as swap
		return false;
	
	tail = stack->tail;
	stack_remove(tail);
	stack_push(stack, tail);

	return true ;
}

bool apply_cmd(t_game *g, enum e_cmd cmd)
{
	if (cmd == SA)
		return cmd_swap(g->a);
	if (cmd == SB)
		return cmd_swap(g->b);
	if (cmd == PA)
		return cmd_push(g->b, g->a);
	if (cmd == PB)
		return cmd_push(g->a, g->b);
	if (cmd == RA)
		return cmd_rotate(g->a);
	if (cmd == RRA)
		return cmd_rrotate(g->a);
	if (cmd == RB)
		return	cmd_rotate(g->b);
	if (cmd == RRB)
		return cmd_rrotate(g->b);
	if (cmd == RR)
		return cmd_rotate(g->a) || cmd_rotate(g->b);
	//if (cmd == RRR)
		return cmd_rrotate(g->a) || cmd_rrotate(g->b);
}

t_cmd *create_cmd(enum e_cmd code, t_cmd *prev)
{
	t_cmd *out;

	out = malloc(sizeof(t_cmd));
	out->move = code;
	out->prev = prev;
	if (prev)
		out->pos = out->prev->pos + 1;
	return (out);
}

enum e_cmd get_counter(const enum e_cmd move)
{
	//prevent infinite loop
	//opt_counter
	//opt use bt generate different counter? 
	if (move == SA)
		return (SA);
	if (move == SB)
		return (SB);
	if (move == PA)
		return (PB);
	if (move == PB)
		return (PA);
	if (move == RA)
		return (RRA);
	if (move == RRA)
		return (RA);
	if (move == RB)
		return (RRB);
	if (move == RRB)
		return (RB);
	if (move == RR)
		return (RRR);
	//if (move == RRR)
	return (RR);
}
