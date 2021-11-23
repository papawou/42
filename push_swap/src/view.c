#include "stack.h"

#include "stdio.h"

void print_stack(t_stack *stack)
{
	t_stack_elem *tmp;

	tmp = stack->head;
	while (tmp)
	{
		printf("%d %c%c\n", tmp->value, (stack->tail == tmp) * 't', (stack->head == tmp) * 'h');
		tmp = tmp->prev;
	}
}