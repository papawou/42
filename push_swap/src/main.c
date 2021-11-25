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
	stack_push(game->a, create_elem(0));
	stack_push(game->a, create_elem(1));
	
	game->b = create_stack();
	stack_push(game->b, create_elem(-1));
	stack_push(game->b, create_elem(-2));
	
	stack_push(game->b, create_elem(-9285));
	
	stack_push(game->b, create_elem(42));
	
	stack_push(game->b, create_elem(76));
	
	stack_push(game->b, create_elem(140));
	
	stack_push(game->b, create_elem(130));
	
	stack_push(game->b, create_elem(150));
	
	stack_push(game->b, create_elem(100));
	
	stack_push(game->b, create_elem(90));
	
	stack_push(game->b, create_elem(85));
	
	print_stack(game->a, game->b);
	bt_game(game);
	print_stack(game->a, game->b);
}