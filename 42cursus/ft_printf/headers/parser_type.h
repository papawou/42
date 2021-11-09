#ifndef PARSER_TYPE_H
# define PARSER_TYPE_H

#include "headers/list.h"

char *parse_c(char c);

char *parse_s(char *s);

char *parse_p(void *p);

char *parse_di(int n);

char *parse_u(unsigned int *n);

char *parse_x();

char *parse_X();

char *parse_percent();

char *parse_word(char *s, t_page **page);

#endif