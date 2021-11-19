#ifndef PARSER_H
# define PARSER_H

#include <stdbool.h>
#include <stdarg.h>
#include <sys/types.h>

#include "t_flags.h"

char		*parse_flags(const char *s, t_flags *flags);
char		*parse_pad(const char *s, t_flags *flags);
char		*parse_type(const char *s, va_list ap, t_flags *flags, size_t *out_len);

#endif