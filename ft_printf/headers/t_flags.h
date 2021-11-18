#ifndef T_FLAGS_H
# define T_FLAGS_H

#include <stdbool.h>

typedef struct s_flags
{
	bool	zero;
	bool	minus;
	bool	plus;
	bool	hash;
	bool	blank;
	int		width;
	int		precision;
} t_flags;

#define _base_HEX "0123456789ABCDEF"
#define _base_hex "0123456789abcdef"
#define _base_10 "0123456789"

#define _base_len_hex 16
#define _base_len_10 10

typedef struct s_va
{
	char *s;
	size_t len;
} t_va;

#define va_base_HEX (t_va) {.s = _base_HEX, .len = _base_len_hex}
#define va_base_hex (t_va) {.s = _base_hex, .len = _base_len_hex}
#define va_base_10 (t_va) {.s = _base_10, .len = _base_len_10}

#endif