#include "parser.h"
#include "view.h"
#include "stack_swap.h"
#include "stack.h"
#include "stack_cmd.h"
#include "game.h"
#include "bcktrack.h"
#include <stdio.h>
#include "stack_hist.h"
#include <time.h> 

int	main()
{
	t_game *g;
	
	g = create_game();
	/*

	PA != PB

	*/
	stack_push(g->a, create_elem(-564));
	stack_push(g->a, create_elem(9));
	stack_push(g->a, create_elem(1100));
	
	stack_push(g->b, create_elem(150));
	stack_push(g->a, create_elem(-150));
	stack_push(g->a, create_elem(7415));
	stack_push(g->a, create_elem(-70));
	
	//25 work
	//25 doenst work
	time_t begin = time( NULL );
	print_stacks(g->a, g->b);

	printf("res: %d - ", bt_game(g));

	printf("%d\n", g->entry->pos);
	print_stacks(g->a, g->b);
	time_t end = time(NULL);
	unsigned long secondes = (unsigned long) difftime( end, begin );
  printf( "Finished in %ld sec\n", secondes);
}

	/* to test
	bt_game

	apply_cmd(get_counter cancel move)
	//hist
	hystory_unique
	copy_stack_to_hist
	hist_to_stack

	//cmd]
	create_cmd
	//
	game_is_sorted
	*/