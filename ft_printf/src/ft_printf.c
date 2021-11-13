#include <stdarg.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "headers/ft_printf.h"
#include "headers/parser_flags.h"
#include "headers/format_types.h"

int ft_printf(const char *s, ...)
{
	va_list ap;
	char		type;

	va_start(ap, s);
	while (*s)
	{
		if (*s != '%') //parse_word
			write(1, *s, 1);
		else
		{ //format
			t_flags *flags;
			s = parse_flags(s, &flags); //parse flags
			s = parse_pad(s, flags);
			s = parse_type(s, ap, flags);
		}
	}
	va_end(ap);
}
