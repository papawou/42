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

void		reset_flags(t_flags *flags);
#endif