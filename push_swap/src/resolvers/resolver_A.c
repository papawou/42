/*
while a->size
	push minus B
while b->size
	push A
*/

#include "game.h"
#include "stack/getters.h"
#include "resolvers/resolvers.h"

unsigned int wrap_resolver(t_game *g, f_resolver resolv)
{
	if (game_is_sorted(g))
		return 0;
	return resolv(g);
}

unsigned int resolver_A(t_game *g)
{
	/*
		SELECTION_SORT
		PB a->minus ...
		PA ...s
	*/
	unsigned int moves;
	t_stack_elem *minus;
	unsigned int idx;

	moves =  0;
	while (g->a->size)
	{
		minus = find_minus(g->a);
		idx = idx_by_elem(minus, false);
		moves += idx;
		while(idx--)
			apply_move(g, RA);
		apply_move(g, PB);
		++moves;
	}
	moves += g->b->size;
	while(g->b->size)
		apply_move(g, PA);
	return moves;
}