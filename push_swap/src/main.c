#include "parser.h"
#include "view.h"
#include "stack.h"

int	main(int argc, char *argv[])
{
	t_stack *stack;
	if (argc > 1)
	{
		stack = parse_args(argv + 1, argc - 1);
		stack_rpush(stack, create_elem(8));	
		print_stack(stack);
		//swap(stack, stack->tail, stack->head);
	}
}