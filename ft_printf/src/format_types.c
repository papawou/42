#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "headers/t_flags.h"
#include "headers/format_flags.h"
#include "headers/ft_utils.h"
/*
csdiuxX
'#0-+ (int).(int)'
*/

char *format_c(unsigned char c, t_flags *flags)
{
	char *out;

	if (flags->precision >= 0)
		return NULL;
	out = malloc(2);
	out[0] = c;
	out[1] = 0;

	return out;
}

char *format_s(char *s, t_flags *flags)
{
	char		*out;
	char		*s_precision;
	size_t	curr_len;

	//if (flags->hash || flags->blank || flags->plus || flags->zero) // flags incorrect for type
	flags->zero = false;
	curr_len = format_precision_s(s, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, 0, flags);
	if (s_precision != s)
		free(s_precision);
	return (out);
}

char *format_di(int n, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;
	bool is_negative;

	//if (flags->hash) // flags incorrect
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		curr_len = q_utoa(-n, _base_10, &s);
	}
	else
		curr_len = q_utoa(n, _base_10, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, (is_negative || flags->blank || flags->plus), flags);
	if ((is_negative || flags->blank || flags->plus) && !flags->zero
		&& 0 <= flags->width && (curr_len + 1) < (size_t) flags->width)
		out[flags->width - curr_len - 1] = flags->blank * ' ' + (flags->plus && !is_negative) * '+' + is_negative * '-';
	else if (is_negative || flags->blank || flags->plus)
		out[0] = flags->blank * ' ' + (flags->plus && !is_negative) * '+' + is_negative * '-';
	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

char *format_u(unsigned int n, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	//if (flags->hash || flags->blank || flags->plus) //flags incorrect type
	curr_len = q_utoa(n, _base_10, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, 0, flags);
	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

char *format_p(uintptr_t p, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_utoa(p, _base_hex, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, 1);
	out = format_width(s_precision, curr_len, 2, flags);
	if (flags->minus && curr_len + 2 < (size_t) flags->width)
	{
		out[flags->width - curr_len - 2] = '0';
		out[flags->width - curr_len - 1] = 'x';
	}
	else
	{
		out[0] = '0';
		out[1] = 'x';
	}
	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

char *format_x(int n, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_utoa(n, _base_hex, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);

	out = format_width(s_precision, curr_len, flags->hash * 2, flags);
	
	if (flags->minus && flags->hash && curr_len + flags->hash * 2 < (size_t) flags->width)
	{
		out[flags->width - curr_len - 2] = '0';
		out[flags->width - curr_len - 1] = 'x';
	}
	else if (flags->hash)
	{
		out[0] = '0';
		out[1] = 'x';
	}

	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

char *format_X(int n, t_flags *flags)
{
	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_utoa(n, _base_HEX, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags->hash * 2, flags);
	
	if (flags->minus && flags->hash && curr_len + flags->hash * 2 < (size_t) flags->width)
	{
		out[flags->width - curr_len - 2] = '0';
		out[flags->width - curr_len - 1] = 'X';
	}
	else if (flags->hash)
	{
		out[0] = '0';
		out[1] = 'X';
	}

	if (s_precision != s)
		free(s_precision);
	free(s);
	return (out);
}

#include <stdarg.h>
ssize_t parse_type(const char *s, va_list ap, t_flags *flags, size_t *out_len)
{
	t_va va;
	if (*s == 'c')
		va = format_c((unsigned char) va_arg(ap, int), flags);
	else if (*s == 's')
		va = format_s(va_arg(ap, char *), flags);
	else if (*s == 'p')
		va = format_p(va_arg(ap, uintptr_t), flags);
	else if (*s == 'd' || *s == 'i')
		va = format_di(va_arg(ap, int), flags);
	else if (*s == 'u')
		va = format_u(va_arg(ap, unsigned int), flags);
	else if (*s == 'x')
		va = format_x(va_arg(ap, int), flags);
	else if (*s == 'X')
		va = format_X(va_arg(ap, int), flags);
	else if(*s == '%')
	{
		out_len += write(1, "%", 1);
		return (s + 1);
	}
	if (va.s == NULL)
		return (NULL);
	*out_len += write(1, va.s, va.len);
	free(va.s);
	return (s + 1); //format error
}

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void)
{
	t_flags flags = {.blank = 0, .hash = 0, .plus = 0, .zero = 1, .minus = 1, .width = 5, .precision = 1};
	flags.zero = (flags.zero && !flags.minus && flags.precision == -1);
	flags.blank = flags.blank && !flags.plus;
	printf("%s", format_di(123, &flags));
	//printf("%0.1d", 123);
	return 0;
}