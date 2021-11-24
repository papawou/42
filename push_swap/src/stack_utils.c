#include <stdbool.h>
#include "stack.h"

bool stack_is_sorted(t_stack *stack)
{
	t_stack_elem *tmp;
	t_stack_elem lowest;
	
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