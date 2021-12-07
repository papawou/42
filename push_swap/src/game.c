#include <stdbool.h>
#include <stdlib.h>

#include "game.h"
#include "stack/stack.h"

t_game *create_game()
{
	t_game *out;

	out = malloc(sizeof(t_game));
	out->a = create_stack();
	out->b = create_stack();
	out->entry = NULL;
	return (out);
}

bool game_is_sorted(t_game *g)
{
	return (stack_is_sorted(g->a) && g->b->size == 0);
}