#ifndef GAME_H
#define GAME_H

#include "stack.h"
#include "stack_cmd.h"

typedef struct s_game
{
	t_stack *a;
	t_stack	*b;
	t_cmd		*entry;
} t_game;

#endif