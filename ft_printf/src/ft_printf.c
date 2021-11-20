#include <sys/types.h>
#include <stdarg.h>
#include <unistd.h>

#include "parser.h"
#include "t_flags.h"

int ft_printf(const char *s, ...)
{
	t_flags flags;
	int	out_len;
	va_list ap;

	va_start(ap, s);
	out_len = 0;
	while (s != NULL && *s)
	{
		if (*s != '%') //parse_word
			out_len += write(1, s++, 1);
		else
		{
			++s;
			reset_flags(&flags);
			s = parse_flags(s, &flags);
			s = parse_pad(s, ap, &flags);
			s = parse_type(s, ap, &flags, &out_len);
		}
	}
	va_end(ap);
	if (s == NULL)
			return (-1);
	return (out_len);
}

/*
#include <stdio.h>
#include <limits.h>

int main()
{
	printf("-\n%d", ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
}
*/