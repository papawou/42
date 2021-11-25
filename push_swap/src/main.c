#include "parser.h"
#include "view.h"
#include "stack_swap.h"
#include "stack.h"
#include "stack_cmd.h"
#include "game.h"
#include "bcktrack.h"

int	main(int argc, char *argv[])
{
	t_game *game;
	
	game = create_game();
	
	game->a = create_stack();
	stack_push(game->a, create_elem(0));
	stack_push(game->a, create_elem(1));
	
	game->b = create_stack();
	stack_push(game->b, create_elem(-1));
	stack_push(game->b, create_elem(-2));
	
	print_stack(game->a, game->b);
}