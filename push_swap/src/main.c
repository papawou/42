#include "parser.h"
#include "view.h"
#include "stack_swap.h"
#include "stack.h"
#include "stack_cmd.h"
#include "game.h"
#include "bcktrack.h"

int	main()
{
	t_game *game;
	
	game = create_game();
	
	game->a = create_stack();
	game->b = create_stack();
	


	stack_push(game->a, create_elem(5));
	
	stack_push(game->a, create_elem(15));
	stack_push(game->b, create_elem(-20));
	stack_push(game->a, create_elem(-10));
	stack_push(game->a, create_elem(0));

	//25 work



	
	//25 doenst work


	game->b = create_stack();
	
	print_stack(game->a, game->b);
	bt_game(game);
	print_stack(game->a, game->b);
}