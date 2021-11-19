#ifndef FORMAT_FLAGS_H
# define FORMAT_FLAGS_H

#include <sys/types.h>
#include "t_flags.h"

int	print_decimal(t_va va_s, t_va va_prefix, t_flags *flags);
int	print_c(const char c, int count);
#endif