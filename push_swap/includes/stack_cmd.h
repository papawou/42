#ifndef STACK_CMD_H
#define STACK_CMD_H

#include <stdbool.h>
#include "stack.h"
#include "game.h"

typedef struct s_game t_game;

enum e_cmd
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
	enum e_cmd move;
	struct s_cmd *prev;
	unsigned int pos;
} t_cmd;

bool apply_cmd(t_game *g, enum e_cmd cmd);

t_cmd *create_cmd(enum e_cmd code, t_cmd *prev);
enum e_cmd get_counter(const enum e_cmd move);
#endif