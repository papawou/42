/*
while a->size
	push minus B
while b->size
	push A
*/

#include "game.h"

void resolver_A(t_game *g)
{
	unsigned int moves;
	t_stack_elem *minus;
	unsigned int idx;

	moves =  0;
	while (g->a->size)
	{
		minus = find_minus(g->a);
		idx = get_idx_by_elem(minus);
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