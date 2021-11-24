#include <stdbool.h>

#include "game.h"
#include "stack_utils.h"

bool g_is_sorted(t_game *g)
{
	return (stack_is_sorted(g->a) && stack_is_sorted(g->b));
}