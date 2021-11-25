#include <stdbool.h>

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
	if (cmd == RRR)
		return cmd_rrotate(g->a) || cmd_rrotate(g->b);
}

t_cmd *create_cmd(enum e_cmd code, t_cmd *prev)
{
	t_cmd *out;

	out = malloc(sizeof(t_cmd));
	out->move = code;
	out->prev = prev;
	out->prev = 0;  
	if (prev)
		out->prev = out->prev->pos + 1;
	return (out);
}

enum e_cmd get_counter(const enum e_cmd move)
{
	//prevent infinite loop
	//opt_counter
	//opt use bt generate different counter? 
	if (SA)
		return (SA);
	if (SB)
		return (SB);
	if (PA)
		return (PB);
	if (PB)
		return (PA);
	if (RA)
		return (RRA);
	if (RRA)
		return (RA);
	if (RB)
		return (RRB);
	if (RRB)
		return (RB);
	if (RR)
		return (RRR);
	if (RRR)
		return (RR);
}
