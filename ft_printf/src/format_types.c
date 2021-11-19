#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "t_flags.h"
#include "t_va.h"
#include "base_helpers.h"
#include "format_flags.h"
#include "ft_utils.h"

/*
csdiuxX
'#0-+ (int).(int)'
*/

size_t	format_c(unsigned char c)
{
	return write(1, &c, 1);
}

size_t	format_s(char *s, t_flags *flags)
{
	size_t	out_len;
	size_t	i;

	i = 0;
	out_len = 0;
	if (flags->minus)
	{
		while (*s &&
			(flags->precision == -1 || (0 <= flags->precision && i < (size_t) flags->precision))
			&& ++i) //spre
			out_len += write(1, s + i - 1, 1);
		out_len += print_c(' ', (i < (size_t) flags->width) * (flags->width - i));
	}
	else
	{
		while (s[i] &&
		(flags->precision == -1 || (0 < flags->precision && i < (size_t) flags->precision))) //count spre_len
			++i;
		out_len += print_c(' ', (i < (size_t) flags->width) * (flags->width - i));
		out_len += write(1, s, i);	//spre
	}
	return (out_len);
}

size_t	format_di(int n, t_flags *flags)
{
	bool		is_negative;
	t_va		va_s;
	t_va		va_prefix;

	is_negative = n < 0;
	if (is_negative)
		va_s = utoa(-n, _va_base_10);
	else
		va_s = utoa(n, _va_base_10);
	va_prefix.len = ((flags->blank || flags->plus) && !is_negative) || is_negative;
	va_prefix.s = NULL;
	if (va_prefix.len)
	{
		va_prefix.s = malloc(va_prefix.len + 1);
		va_prefix.s[va_prefix.len] = 0;
		va_prefix.s[0] = (flags->blank * ' ' + flags->plus * '+') * !is_negative + is_negative * '-';
	}
	return (print_decimal(va_s, va_prefix, flags));
}

size_t	format_u(unsigned int n, t_flags *flags)
{
	t_va	va_s;

	va_s = utoa(n, _va_base_10);
	return (print_decimal(va_s, (t_va) {.s = NULL, .len = 0}, flags));
}

size_t	format_hex(uintptr_t n, bool caps, bool prefix, t_flags *flags)
{
	t_va	va_s;
	t_va	va_prefix;
	t_va	va_base;

	if (caps)
		va_base = _va_base_HEX;
	else
		va_base = _va_base_hex;
	va_s = utoa(n, va_base);
	va_prefix.s = NULL;
	va_prefix.len = prefix * 2;
	if (va_prefix.len)
	{
		va_prefix.s = malloc(va_prefix.len + 1);
		va_prefix.s[va_prefix.len] = 0;
		va_prefix.s[0] = '0';
		va_prefix.s[1] = caps * 'X' + !caps * 'x';
	}
	return (print_decimal(va_s, va_prefix, flags));
}

#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void)
{
	t_flags flags = {.blank = 0, .hash = 0, .plus = 0, .zero = 1, .minus = 1, .width = 5, .precision = 1};
	flags.zero = (flags.zero && !flags.minus && flags.precision == -1);
	flags.blank = flags.blank && !flags.plus;
	printf("%ld", format_di(123, &flags));
	//printf("%0.1d", 123);
	return 0;
}

/*

size_t	format_p(uintptr_t p, t_flags *flags)
{
	t_va va_s;
	t_va va_prefix;

	va_s.len = q_utoa(p, _base_hex, &va_s.s);
	va_prefix.s = NULL;
	va_prefix.len = 2;
	va_prefix.s = malloc(va_prefix.len + 1);
	va_prefix.s[0] = '0';
	va_prefix.s[1] = 'x';
	return (print_decimal(va_s, va_prefix, flags));
}

size_t	format_x(unsigned int n, t_flags *flags)
{
	t_va va_s;
	t_va va_prefix;

	va_s.len = q_utoa(n, _base_hex, &va_s.s);
	va_prefix.s = NULL;
	va_prefix.len = flags->hash * 2;
	if (va_prefix.len)
	{
		va_prefix.s = malloc(va_prefix.len + 1);
		va_prefix.s[0] = '0';
		va_prefix.s[1] = 'x';
	}
	return (print_decimal(va_s, va_prefix, flags));
}

size_t	format_X(unsigned int n, t_flags *flags)
{
	t_va va_s;
	t_va va_prefix;

	va_s.len = q_utoa(n, _base_hex, &va_s.s);
	va_prefix.s = NULL;
	va_prefix.len = flags->hash * 2;
	if (va_prefix.len)
	{
		va_prefix.s = malloc(va_prefix.len + 1);
		va_prefix.s[0] = '0';
		va_prefix.s[1] = 'X';
	}
	return (print_decimal(va_s, va_prefix, flags));
}
*/