#ifndef PARSER_FORMAT_H
#define PARSER_FORMAT_H

#include <stdbool.h>
#include <sys/types.h>

typedef struct s_flags
{
	bool zero_pad;
	bool justify_left;
	bool sign;
	bool hash;
	bool space;

	int min;
	int max;
} t_flags;

#endif