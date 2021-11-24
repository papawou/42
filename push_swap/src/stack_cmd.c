#include <stdbool.h>

#include "stack.h"
#include "stack_swap.h"
#include "stack_cmd.h"
#include "game.h"

void cmd_swap(t_stack *stack)
{
	if (stack && stack->size > 1)
		swap(stack->head, stack->head->prev);
}

void cmd_push(t_stack *src, t_stack *dst)
{
	t_stack_elem *elem;

	if (!src || !dst)
		return ;
	elem = src->head;
	stack_remove(elem);
	stack_push(dst, elem);
}

void cmd_rotate(t_stack *stack) //if stack->size == 2 same as swap
{
	t_stack_elem *head;

	if (!(stack && stack->size > 1))
		return ;
	head = stack->head;
	stack_remove(head);
	stack_rpush(stack, head);
}

void cmd_rrotate(t_stack *stack)
{
	t_stack_elem *tail;

	if (!(stack && stack->size > 1)) //if stack->size == 2 same as swap
		return ;
	tail = stack->tail;
	stack_remove(tail);
	stack_push(stack, tail);
}


bool apply_cmd(const t_game *g, enum e_cmd cmd)
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
		return cmd_rotate(g->a) && cmd_rotate(g->b);
	if (cmd == RRR)
		return cmd_rrotate(g->a) && cmd_rrotate(g->b);
}