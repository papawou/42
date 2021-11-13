#ifndef FORMAT_FLAGS_H
# define FORMAT_FLAGS_H

#include "t_flags.h"
#include <sys/types.h>

char *format_width(char *s, t_flags *flags, bool print_zero);
char *format_precision_d(char *s, size_t max);
char *format_precision_s(char *s, size_t precision);
#endif