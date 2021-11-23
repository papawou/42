#include "parser.h"
#include "view.h"
#include "stack_swap.h"
#include "stack.h"
#include "stack_cmd.h"

int	main(int argc, char *argv[])
{
	t_stack *stack;
	t_stack *stackB;

	stackB = create_stack();
	stack_push(stackB, create_elem(-1));
	stack_push(stackB, create_elem(-8));
	stack_push(stackB, create_elem(-5));
	if (argc > 1)
	{
		stack = parse_args(argv + 1, argc - 1);	
		print_stack(stack, stackB);
		
		//operation
		cmd_rotate(stack);
		
		
		
		//result
		print_stack(stack, stackB);
	}
}