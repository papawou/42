//obj : find less ways possible given rules
//break : pile is sorted
//return best track
#include <stdbool.h>

#include "stack.h"
#include "stack_cmd.h"
#include "game.h"


// - prevent infinite loop like rr/r r/rr
// - use of history mode ?

bool bt_game(const t_game *g, const unsigned int best_score)
{
	enum e_cmd cmd;

	cmd = PA;
	while (cmd <= RRR)
	{
		if (g->entry->move == get_counter(cmd) && ++cmd) //opt counter
			continue ;
		if(!apply_cmd(g, cmd) && ++cmd) //opt move_not_effect
			continue ;

		if (game_is_sorted(g)) //solution found
			return true;
		if (bt_game(g, best_score)) //solution found rec
			return true;
		else
			apply_cmd(g, get_counter(cmd)); //wrong path back to arg state
		++cmd;
	}
	return false;	
}