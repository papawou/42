//obj : find less ways possible given rules
//break : pile is sorted
//return best track
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "game.h"
#include "stack_cmd.h"
#include "stack_hist.h"

static bool history_unique(t_game *g)
{
	t_cmd				 *cmd_last;
	t_stack_hist *a;
	t_stack_hist *b;

	a = copy_stack_to_hist(g->a);
	b = copy_stack_to_hist(g->b);

	cmd_last = g->entry;
	while (cmd_last)
	{
		apply_move(g, get_counter(cmd_last->move)); //cancel cmd_last move
		if (compare_hist_stack(g->a, a) && compare_hist_stack(g->b, b)) //duplicate result
		{
			hist_to_stack(g->a, a);
			hist_to_stack(g->b, b);
			return false;
		}
		cmd_last = cmd_last->prev;
	}
	hist_to_stack(g->a, a);
	hist_to_stack(g->b, b);
	return true;
}

bool bt_game(t_game *g)
{
	t_cmd				*cand_cmd;
	enum e_move	move;
	static unsigned long long test = 0;

	move = SA;
	if (g->entry && g->entry->pos > 5)
		return false;
	while (move <= RRR)
	{
		if (g->entry  && g->entry->move == get_counter(move) && ++move) //opt_counter
			continue ;
		//history comp
		//	rotate * len == counter || rrotate
		//	rotate * len - n == counter (rrotate can do same with less move)
		if(!apply_move(g, move) && ++move) //opt_move_no_effect
			continue ;

		//register new cmd
		cand_cmd = create_cmd(move, g->entry);
		g->entry = cand_cmd;

		if (history_unique(g)) //noinfinit prevent same game before
		{
			if (game_is_sorted(g)) //solution found
				return true;
			if (bt_game(g)) //recursive call solution found
				return true;
		}

		//reverse state of game
		g->entry = g->entry->prev;
		free(cand_cmd);
		apply_move(g, get_counter(move));
		++move;
	}
	printf("%lld\n", ++test);
	return false;
}