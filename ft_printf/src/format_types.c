#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "headers/t_flags.h"

/*
csdiuxX
'#0-+ (int).(int)'
*/

char *parse_c(unsigned char c, t_flags *flags)
{
	int i = 0;
}

char *parse_s(char *s, t_flags *flags)
{
	char		*out;
	char		*s_precision;
	size_t	curr_len;

	curr_len = format_precision_s(s, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, false);
	if (s_precision != s)
		free(s_precision);
	return (out);
}

char *parse_di(int n, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_itoa(n, "0123456789", &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

char *parse_u(unsigned int n, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_utoa(n, _base_10, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

char *parse_p(uintptr_t p, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_utoa(p, _base_hex, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

char *parse_x(int n, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_utoa(n, _base_hex, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

char *parse_X(int n, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_utoa(n, _base_HEX, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

#include <stdarg.h>
char *parse_type(const char *s, va_list ap, t_flags *flags)
{
	if (*s == 'c')
		return parse_c(va_arg(ap, unsigned char), flags);
	else if (*s == 's')
		return parse_s(va_arg(ap, char *), flags);
	else if (*s == 'p')
		return parse_p(va_arg(ap, uintptr_t), flags);
	else if (*s == 'd' || *s == 'i')
		return parse_di(va_arg(ap, int), flags);
	else if (*s == 'u')
		return parse_u(va_arg(ap, unsigned int), flags);
	else if (*s == 'x')
		return parse_x(va_arg(ap, int), flags);
	else if (*s == 'X')
		return parse_X(va_arg(ap, int), flags);
	else if(*s == '%')
	{
		write(1, "%", 1);
		return (s + 1);
	}
	return (NULL);
}