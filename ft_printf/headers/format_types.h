#ifndef FORMAT_TYPES_H
# define FORMAT_TYPES_H

#include "headers/t_flags.h"
#include "stdarg.h"

char *parse_type(const char *s, va_list ap, t_flags *flags);
#endif