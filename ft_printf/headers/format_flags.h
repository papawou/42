#ifndef FORMAT_FLAGS_H
# define FORMAT_FLAGS_H

#include <sys/types.h>
#include "t_flags.h"

size_t	print_decimal(t_va va_s, t_va va_prefix, t_flags *flags);
size_t	print_c(const char c, size_t count);
#endif