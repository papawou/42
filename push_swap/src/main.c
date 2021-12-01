#include <stdio.h>
#include <time.h> 

#include "stack/swap.h"
#include "stack/stack.h"

#include "cmd.h"
#include "hist.h"

#include "parser.h"
#include "view.h"
#include "game.h"
#include "resolvers/bcktrack.h"
#include "resolvers/resolver_A.h"

int	main()
{
	t_game *g;
	
	g = create_game();
	
	stack_push(g->a, create_elem(-8));
	stack_push(g->a, create_elem(8956));
	stack_push(g->a, create_elem(8));
	stack_push(g->a, create_elem(20));
	stack_push(g->a, create_elem(-1));
	stack_push(g->a, create_elem(3));
	stack_push(g->a, create_elem(5));
	stack_push(g->a, create_elem(4));
	stack_push(g->a, create_elem(-10));

	time_t begin = time( NULL );
	print_stacks(g->a, g->b);

	printf("res: %lld - \n", resolver_a(g));

	//printf("%d\n", g->entry->pos);
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