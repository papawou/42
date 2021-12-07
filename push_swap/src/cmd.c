#include <stdbool.h>
#include <stdlib.h>

#include "stack/stack.h"
#include "stack/swap.h"
#include "cmd.h"
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

static bool cmd_rotate(t_stack *stack)
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

bool apply_move(t_game *g, enum e_move move)
{
	int test;

 	test = 0;
	if (move == SA)
		return cmd_swap(g->a);
	if (move == SB)
		return cmd_swap(g->b);
	if (move == PA)
		return cmd_push(g->b, g->a);
	if (move == PB)
		return cmd_push(g->a, g->b);
	if (move == RA)
		return cmd_rotate(g->a);
	if (move == RRA)
		return cmd_rrotate(g->a);
	if (move == RB)
		return	cmd_rotate(g->b);
	if (move == RRB)
		return cmd_rrotate(g->b);
	if (move == RR)
	{
		test += cmd_rotate(g->a);
		test += cmd_rotate(g->b);
		return  test;
	}
	//(move == RRR)
	test += cmd_rrotate(g->a);
	test += cmd_rrotate(g->b);
	return test;
}

t_cmd *create_cmd(enum e_move move, t_cmd *prev)
{
	t_cmd *out;

	out = malloc(sizeof(t_cmd));
	out->move = move;
	out->prev = prev;
	out->pos = 1;
	if (prev)
		out->pos = out->prev->pos + 1;
	return (out);
}

enum e_move get_counter(const enum e_move move)
{
	//opt ?use bt generate different counter
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
	return (RR); //move == RRR
}
