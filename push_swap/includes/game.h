#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#include "stack/stack.h"
#include "cmd.h"

typedef struct s_cmd t_cmd;

typedef struct s_game
{
	t_stack *a;
	t_stack	*b;
	t_cmd		*entry;
} t_game;

bool game_is_sorted(t_game *g);
t_game *create_game();

#endif