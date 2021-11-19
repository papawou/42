#ifndef FORMAT_TYPES_H
# define FORMAT_TYPES_H

#include <stdint.h>
#include <sys/types.h>
#include "t_flags.h"


size_t	format_c(unsigned char c);
size_t	format_s(char *s, t_flags *flags);
size_t	format_di(int n, t_flags *flags);
size_t	format_u(unsigned int n, t_flags *flags);
size_t	format_hex(uintptr_t n, bool caps, bool prefix, t_flags *flags);
#endif