#include "parser.h"
#include "view.h"
#include "stack_swap.h"
#include "stack.h"
#include "stack_cmd.h"
#include "game.h"
#include "bcktrack.h"
#include <stdio.h>

int	main()
{
	t_game *g;
	
	g = create_game();

/*
	stack_push(game->a, create_elem(5));
	stack_push(game->a, create_elem(15));
	stack_push(game->b, create_elem(-20));
	stack_push(game->b, create_elem(50));
	stack_push(game->a, create_elem(-10));
	stack_push(game->a, create_elem(0));
	//25 work
	//25 doenst work
*/

	/* to test

	bt_game

	apply_cmd(get_counter cancel move)
	//hist
	hystory_unique
	copy_stack_to_hist
	hist_to_stack

	//cmd
	create_cmd
	//
	game_is_sorted
	*/
	
	stack_push(g->a, create_elem(5));
	stack_push(g->a, create_elem(15));

	stack_push(g->b, create_elem(-10));
	stack_push(g->b, create_elem(-20));
	
	print_stack(g->a, g->b);

	printf("%d\n", apply_move(g, RR));
//	printf("%d\n", apply_move(g, get_counter(RR)));

	print_stack(g->a, g->b);
}