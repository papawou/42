/*
obj : find less ways possible given rules
break : pile is sorted
return best track
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack/stack.h"
#include "game.h"
#include "cmd.h"
#include "hist.h"
#include "view.h"

static bool history_unique(t_game *g)
{
	t_cmd *cmd_last;
	t_stack_hist *a;
	t_stack_hist *b;

	//printf("%s_______%d\n", get_move_txt(g->entry->move), g->entry->pos);
	a = stack_to_hist(g->a);
	b = stack_to_hist(g->b);
	//print_stacks_line(g->a, g->b);
	//print_hists_line(a, b);
	cmd_last = g->entry;
	while (cmd_last)
	{
		apply_move(g, get_counter(cmd_last->move));											//cancel cmd_last move
		if (compare_hist_stack(g->a, a) && compare_hist_stack(g->b, b)) //duplicate result
		{
			//printf("____!!SAME!!____%d\n", cmd_last->pos - 1);
			hist_to_stack(g->a, a);
			hist_to_stack(g->b, b);
			//print_stacks(g->a, g->b);
			return false;
		}
		cmd_last = cmd_last->prev;
	}
	hist_to_stack(g->a, a);
	hist_to_stack(g->b, b);
	return true;
}

unsigned int bt_game(t_game *g)
{
	static unsigned int best_score = 0;
	t_cmd *cand_cmd;

	if (game_is_sorted(g))
	{
		printf("ALREADY SORTED\n");
		return 0;
	}
	cand_cmd = create_cmd(SA, g->entry);
	g->entry = cand_cmd;
	while (cand_cmd != NULL)
	{
		if (cand_cmd->move > RRR)
		{ //exit branch
			g->entry = g->entry->prev;
			free(cand_cmd);
			cand_cmd = g->entry;
			if (cand_cmd == NULL) //dead end no solutio foudn
				break;
			apply_move(g, get_counter(cand_cmd->move));
			++cand_cmd->move;
			continue;
		}
		if (g->entry->prev && g->entry->prev->move == get_counter(cand_cmd->move) && ++cand_cmd->move) //opt_counter
			continue;
		if (!apply_move(g, cand_cmd->move) && ++cand_cmd->move) //opt_move_no_effect
			continue;

		if (history_unique(g)) //noinfinit prevent same game before
		{
			if (game_is_sorted(g)) //solution found
			{
				best_score = cand_cmd->pos;
				printf("%d\n", best_score);

				apply_move(g, get_counter(cand_cmd->move)); //stop branch
				cand_cmd->move = RRR + 1;
				continue;
			}
			if (best_score == 0 || cand_cmd->pos + 1 < best_score) //continue branch
			{
				cand_cmd = create_cmd(SA, g->entry);
				g->entry = cand_cmd;
				//printf("%s %d\n", "->", g->entry->pos);
				continue;
			}
		}
		else
		{
			//	printf("%s", "|||");
		}
		//	printf("\n");
		//test next leaf of branch
		apply_move(g, get_counter(cand_cmd->move));
		++cand_cmd->move;
	}
	return best_score;
}

unsigned int bt_game_depth(t_game *g)
{

	/*
		SA
		PB
		SA SA
			 PB
		PB SA
			 PB
		...
		*/
	size_t depth_pass;
	t_cmd *cand_cmd;

	depth_pass = 1;
	cand_cmd = create_cmd(SA, g->entry);
	g->entry = cand_cmd;
	while (1)
	{

		if (cand_cmd->move > RRR)
		{
			if (cand_cmd->prev == NULL)
			{
				printf("depth done: %ld\n", depth_pass);
				cand_cmd->move = SA;
				++depth_pass;
			}
			else
			{
				g->entry = cand_cmd->prev;
				free(cand_cmd);
				cand_cmd = g->entry;
				apply_move(g, get_counter(cand_cmd->move));
				++cand_cmd->move;
			}
			continue;
		}
		if (cand_cmd->prev && cand_cmd->prev->move == get_counter(cand_cmd->move))
		{
			++cand_cmd->move;
			continue;
		}
		if (!apply_move(g, cand_cmd->move))
		{
			++cand_cmd->move;
			continue;
		}
		if (cand_cmd->pos == depth_pass)
		{
			if (game_is_sorted(g))
			{
				print_cmd(g->entry);
				return cand_cmd->pos;
			}
			apply_move(g, get_counter(cand_cmd->move));
			++cand_cmd->move;
		}
		else
		{
			cand_cmd = create_cmd(SA, g->entry);
			g->entry = cand_cmd;
		}
	}
	return 0;
}


unsigned int bt_q_sort(t_game *g)
{
	size_t depth_pass;
	t_cmd *cand_cmd;

	depth_pass = 1;
	cand_cmd = create_cmd(SA, g->entry);
	g->entry = cand_cmd;
	while (1)
	{
		if (cand_cmd->move > RRR)
		{
			if (cand_cmd->prev == NULL)
			{
				printf("depth done: %ld\n", depth_pass);
				cand_cmd->move = SA;
				++depth_pass;
			}
			else
			{
				g->entry = cand_cmd->prev;
				free(cand_cmd);
				cand_cmd = g->entry;
				apply_move(g, get_counter(cand_cmd->move));
				++cand_cmd->move;
			}
			continue;
		}

		if (cand_cmd->move == RRR || cand_cmd->move == RA || cand_cmd->move == RR || cand_cmd->move == RRA)
		{
			++cand_cmd->move;
			continue;
		}

		if (cand_cmd->prev && cand_cmd->prev->move == get_counter(cand_cmd->move))
		{
			++cand_cmd->move;
			continue;
		}

		if (!apply_move(g, cand_cmd->move))
		{
			++cand_cmd->move;
			continue;
		}

		if (cand_cmd->pos == depth_pass)
		{
			if (stack_is_sorted(g->b))
			{
				print_cmd(g->entry);
				return cand_cmd->pos;
			}
			apply_move(g, get_counter(cand_cmd->move));
			++cand_cmd->move;
		}
		else
		{
			cand_cmd = create_cmd(SA, g->entry);
			g->entry = cand_cmd;
		}
	}
	return 0;
}