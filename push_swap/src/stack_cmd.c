#include "stack.h"
#include "stack_swap.h"


void cmd_swap(t_stack *stack)
{
	if (stack && stack->size > 1 && stack->head->prev)
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

void cmd_rotate(t_stack *stack)
{
	t_stack_elem *head;

	if (!(stack && stack->size && stack->head != stack->tail))
		return ;
	head = stack->head;
	stack_remove(head);
	stack_rpush(stack, head);
}

void cmd_rrotate(t_stack *stack)
{
	t_stack_elem *tail;

	if (!(stack && stack->size && stack->head != stack->tail))
		return ;
	tail = stack->tail;
	stack_remove(tail);
	stack_push(stack, tail);
}