#include <sys/types.h>
#include <stdarg.h>
#include <unistd.h>

#include "parser.h"
#include "t_flags.h"

int ft_printf(const char *s, ...)
{
	t_flags *flags;
	size_t	out_len;
	va_list ap;

	va_start(ap, s);
	flags = create_flags();
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
			reset_flags(flags);
			s = parse_flags(s, flags);
			s = parse_pad(s, flags);
			s = parse_type(s, ap, flags, &out_len);
		}
	}
	va_end(ap);
	return (out_len);
}
