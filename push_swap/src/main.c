#include <stdio.h>
#include <time.h> 

#include "stack/swap.h"
#include "stack/stack.h"

#include "cmd.h"
#include "hist.h"

#include "parser.h"
#include "view.h"
#include "game.h"
#include "resolvers/resolvers.h"

//./push_swap `ruby -e "puts (-2..3).to_a.shuffle.join(' ')"`

int	main(int argc, char *argv[])
{
	//int argc, char *argv[])
	//int args[] = {3, 1, 0, -1, 2, -2};
	
	t_game *g;
	
	g = create_game();
	
	g->a = parse_args(argv + 1, argc - 1);
	//g->a = parse_int_args(args, 6);
	time_t begin = time( NULL );
	print_stacks(g->a, g->b, "start");

	printf("res: %d - \n", wrap_resolver(g, &resolver_B));
	//printf("%d\n", g->entry->pos);

	//print_stacks(g->a, g->b, "exit");
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