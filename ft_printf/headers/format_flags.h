#ifndef FORMAT_FLAGS_H
# define FORMAT_FLAGS_H

#include "t_flags.h"
#include <sys/types.h>

char *format_width(const char *s, const size_t s_len, const size_t prefix_len, const t_flags *flags);
size_t	format_precision_d(char *s, size_t s_len, char **dst, int precision);
size_t format_precision_s(char *s, char **dst, int precision);
#endif