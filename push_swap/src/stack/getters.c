#include <stdlib.h>
#include "stack/stack.h"

t_stack_elem *elem_by_idx(t_stack *A, unsigned int idx, bool tail_start)
{
	/*
		stack[0] == tail_start ? A->tail : A->head
		
		?tothink
		cap ?
			idx >= A->size ?
				stack[A->size - 1] : stack[idx]
			: NULL
	*/
	t_stack_elem *tmp_elem;
	
	if (A->size <= idx)
		return NULL;
	if (tail_start)
		tmp_elem = A->tail;
	else
		tmp_elem = A->head;
	while (idx)
	{
		if (tail_start)
			tmp_elem = tmp_elem->next;
		else
			tmp_elem = tmp_elem->prev;
		--idx;
	}
	return tmp_elem;
}

unsigned int idx_by_elem(t_stack_elem *elem, bool tail_start)
{
	t_stack_elem *tmp_elem;
	unsigned int idx;

	idx = 0;
	tmp_elem = elem;
	while (tmp_elem->next)
	{
		tmp_elem = tmp_elem->next;
		++idx;
	}
	if (tail_start)
		return elem->stack->size - 1 - idx;
	return idx;
}

t_stack_elem *find_minus(t_stack *a)
{
	t_stack_elem	*tmp_elem;
	t_stack_elem	*elem;

	elem = a->head;
	tmp_elem = elem;
	while (tmp_elem)
	{
		if (tmp_elem->value < elem->value)
			elem = tmp_elem;
		tmp_elem = tmp_elem->prev;
	}
	return elem;
}

t_stack_elem *find_max(t_stack *s)
{
	t_stack_elem	*tmp_elem;
	t_stack_elem	*elem;

	elem = s->head;
	tmp_elem = elem;
	while (tmp_elem)
	{
		if (tmp_elem->value > elem->value)
			elem = tmp_elem;
		tmp_elem = tmp_elem->prev;
	}
	return elem;
}