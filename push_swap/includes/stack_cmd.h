#ifndef STACK_CMD_H
#define STACK_CMD_H

#include <stdbool.h>
#include "stack.h"
#include "game.h"

typedef struct s_game t_game;

enum e_move
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_cmd
{
	enum e_move move;
	struct s_cmd *prev;
	unsigned int pos;
} t_cmd;

bool apply_move(t_game *g, enum e_move move);

t_cmd *create_cmd(enum e_move move, t_cmd *prev);
enum e_move get_counter(const enum e_move move);
#endif