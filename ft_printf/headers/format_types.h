#ifndef FORMAT_TYPES_H
# define FORMAT_TYPES_H

#include <stdint.h>
#include <sys/types.h>
#include "t_flags.h"


int	format_c(unsigned char c, t_flags *flags);
int	format_s(char *s, t_flags *flags);
int	format_di(int n, t_flags *flags);
int	format_u(unsigned int n, t_flags *flags);
int	format_hex(unsigned long long n, char type, bool caps, t_flags *flags);
#endif