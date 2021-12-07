#ifndef RESOLVERS_H
#define RESOLVERS_H

#include "game.h"

typedef unsigned int (*f_resolver)(t_game *);

unsigned int bt_game(t_game *g);
unsigned int bt_game_depth(t_game *g);
unsigned int resolver_A(t_game *g);
unsigned int wrap_resolver(t_game *g, f_resolver resolv);
unsigned int q_sort(t_game *g, unsigned int stop_A);
unsigned int q_sort_b(t_game *g, unsigned int stop_A);
unsigned int q_sort_a(t_game *g, unsigned int stop_A);
unsigned int resolver_B(t_game *g);

#endif