#include "game.h"
#include "resolvers/resolvers.h"
#include "stack/getters.h"
#include <stdbool.h>
#include "view.h"
#include <stdio.h>
unsigned int save_target(t_game *g, bool in_A)
{
	unsigned int moves;
	
	moves = 0;
	if (!in_A && ++moves)
		apply_move(g, PA);
	apply_move(g, RA);
	return moves + 1;
}

unsigned int find_pivot(t_stack *s)
{
	unsigned int min;
	unsigned int max;

	min = find_minus(s)->idx_target;
	max = find_max(s)->idx_target;
	return (max - min) / 2 + min;
}

unsigned int resolver_B(t_game *g)
{
	unsigned int pivot;
	t_stack_elem *tmp; 
	unsigned int moves;

	moves = 0;
	pivot = g->a->size / 2;
	while (g->b->size < pivot)
	{
		tmp = g->a->head;
		if (tmp->idx_target <= pivot)
			apply_move(g, PB);
		else
			apply_move(g, RA);
		++moves;
	}
	return moves + q_sort(g, 1);
}

unsigned int q_sort_b(t_game *g, unsigned int stop_A)
{
	t_stack_elem *tmp;
	unsigned int pivot;
	unsigned int stop_B;
	unsigned int moves;


	moves = 0;
/*
	if (g->b->size <= 5)
	{
		//bt_game_depth
		moves += bt_q_sort(g);
		while (g->b->head == g->a->tail + 1)
			save_target(g, false);
		g->entry = NULL;
		if (g->b->size == 0)
			return moves;
	}
*/	
	pivot = find_pivot(g->b);
	stop_B = g->b->size - (g->b->size / 2);
	
	while (stop_B < g->b->size)
	{
		tmp = g->b->head;
		if (tmp->idx_target <= pivot)
		{
			if (tmp->idx_target == g->a->tail->idx_target + 1 || tmp->idx_target == 1)
			{
				moves += save_target(g, false);
				--stop_B;
				while (g->a->head->idx_target == g->a->tail->idx_target +1 && g->a->head->idx_target != stop_A)
					moves += save_target(g, true);
			}
			else if(++moves)
				apply_move(g, RB);
		}
		else if(++moves)
			apply_move(g, PA);
	}
	return moves + q_sort(g, g->a->head->idx_target);
}

unsigned int q_sort_a(t_game *g, unsigned int stop_A)
{
	t_stack_elem *tmp;
	unsigned int moves;

	tmp = g->a->head;
	moves = 0;
	while (tmp->idx_target != stop_A)
	{
		if (tmp->idx_target == g->a->tail->idx_target + 1 || tmp->idx_target == 1) //save
			moves += save_target(g, true);
		else if(tmp->idx_target == tmp->prev->idx_target + 1 && tmp->prev->idx_target == g->a->tail->idx_target + 1)
		{
			apply_move(g, SA);
			++moves;
		}
		else if(++moves)
			apply_move(g, PB);
		tmp = g->a->head;
	}
	return moves + q_sort(g, g->a->head->idx_target); //sort child high branch
}

unsigned int q_sort(t_game *g, unsigned int stop_A)
{
	unsigned int moves;

	moves = 0;
	if (g->b->size > 0)
	{
		if (g->b->size <= 2)
		{
			if (g->b->head->idx_target > g->b->tail->idx_target && ++moves)
				apply_move(g, SB);
			moves += save_target(g, false);
			if (g->b->size != 0)
				moves += save_target(g, false);
		}
		else
			moves += q_sort_b(g, stop_A);
	}
	if (g->a->head->idx_target != stop_A)
		moves += q_sort_a(g, stop_A);
	return moves;
}


