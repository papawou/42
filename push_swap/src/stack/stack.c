#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
//TAIL <prev- A -next> HEAD

t_stack *create_stack()
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;

	return stack;
}

t_stack_elem *create_elem(int value)
{
	t_stack_elem *elem;

	elem = malloc(sizeof(t_stack_elem));
	elem->value = value;
	elem->prev = NULL;
	elem->next = NULL;
	elem->stack = NULL;
	return (elem);
}

void stack_push(t_stack *stack, t_stack_elem *elem) //push to head
{
	if (!stack || !elem)
		return ;
	elem->stack = stack;
	if (stack->head)
	{
		elem->prev = stack->head;
		elem->prev->next = elem;
	}
	else
		stack->tail = elem;
	stack->head = elem;
	++stack->size;
}

void stack_rpush(t_stack *stack, t_stack_elem *elem) //push to tail
{
	if (!stack || !elem)
		return ;
	elem->stack = stack;
	if (stack->tail)
	{
		elem->next = stack->tail;
		elem->next->prev = elem;
	}
	else
		stack->head = elem;
	stack->tail = elem;
	++stack->size;
}

void stack_remove(t_stack_elem *A)
{
	if (!A)
		return ;
	if (A->prev)
		A->prev->next = A->next;
	else
		A->stack->tail = A->next;
	if (A->next)
		A->next->prev = A->prev;
	else
		A->stack->head = A->prev;
	--A->stack->size;
	A->prev = NULL;
	A->next = NULL;
	A->stack = NULL;
}

bool stack_is_sorted(t_stack *stack)
{
	t_stack_elem *tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (!tmp->prev)
			return true;
		else if (tmp->value < tmp->prev->value)
			tmp = tmp->prev;
		else
			return false;
	}
	return true;
}