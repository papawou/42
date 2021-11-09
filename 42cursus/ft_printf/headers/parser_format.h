#ifndef PARSER_FORMAT_H
#define PARSER_FORMAT_H

#include <bool.h>

typedef struct s_flags
{
	bool zero_pad;
	bool justify_left;
	bool sign;
	bool hash;
	bool space;

	size_t min;
	size_t max;
} t_flags;

char *parse_pad(char *s, t_pad **pad);

#endif