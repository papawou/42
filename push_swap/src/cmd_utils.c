#include "stack_cmd.h"
#include "game.h"

enum e_cmd get_counter(const enum e_cmd move)
{
	//prevent infinite loop
	//opt_counter
	//opt use bt generate different counter? 
	if (SA)
		return (SA);
	if (SB)
		return (SB);
	if (PA)
		return (PB);
	if (PB)
		return (PA);
	if (RA)
		return (RRA);
	if (RRA)
		return (RA);
	if (RB)
		return (RRB);
	if (RRB)
		return (RB);
	if (RR)
		return (RRR);
	if (RRR)
		return (RR);
}
