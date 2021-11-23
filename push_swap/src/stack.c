#include <stdlib.h>

#include "stack.h"

t_stack_elem *create_elem(int value)
{
	t_stack_elem *elem;

	elem = malloc(sizeof(t_stack_elem));
	elem->value = value;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

//TAIL prev <<a>> <<1>> <<2>> <<b>> next HEAD
void stack_push(t_stack *stack, t_stack_elem *elem) //push to head
{
	if (stack->head)
	{
		elem->prev = stack->head;
		elem->prev->next = elem;
	}
	else
		stack->tail = elem;
	stack->head = elem;
}

void stack_rpush(t_stack *stack, t_stack_elem *elem) //push to tail
{
	if (stack->tail)
	{
		elem->next = stack->tail;
		elem->next->prev = elem;
	}
	else
		stack->head = elem;
	stack->tail = elem;
}

void swap(t_stack *stack, t_stack_elem *elem1, t_stack_elem *elem2)
{
	elem1 = elem2;
	stack->head = elem1;
}