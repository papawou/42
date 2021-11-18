#include <stdarg.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "headers/ft_printf.h"
#include "headers/parser_flags.h"
#include "headers/format_types.h"
#include "headers/format_types.h"

int ft_printf(const char *s, ...)
{
	size_t	out_len;
	va_list ap;

	va_start(ap, s);
	out_len = 0;
	while (*s)
	{
		if (*s != '%') //parse_word
		{
			write(1, s++, 1);
			++out_len;
		}
		else
		{
			t_flags *flags;
			s = parse_flags(s, &flags);
			s = parse_pad(s, flags);
			s = parse_type(s, ap, flags);
		}
	}
	va_end(ap);
	return 42;
}
