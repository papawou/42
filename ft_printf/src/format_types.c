#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "t_flags.h"
#include "t_va.h"
#include "base_helpers.h"
#include "format_flags.h"
#include "ft_utils.h"
#include "format_types.h"

/*
csdiuxX
'#0-+ (int).(int)'
*/

int	format_c(unsigned char c, t_flags *flags)
{
	int	out_len;
	int	i;

	i = 1;
	out_len = 0;
	if (flags->minus)
	{
		out_len += write(1, &c, 1);
		out_len += print_c(' ', flags->width - i);
	}
	else
	{
		out_len += print_c(' ', flags->width - i);
		out_len += write(1, &c, i);	//spre
	}
	return (out_len);
}

int	format_s(char *s, t_flags *flags)
{
	int	out_len;
	int	i;

	i = 0;
	out_len = 0;
	if (s == NULL)
		s = "(null)";
	if (flags->minus)
	{
		while (s[i] && (i < flags->precision || flags->precision == -1) && ++i) //spre
			out_len += write(1, s + i - 1, 1);
		out_len += print_c(' ', flags->width - i);
	}
	else
	{
		while (s[i] && (i < flags->precision || flags->precision == -1)) //count spre_len
			++i;
		out_len += print_c(' ', flags->width - i);
		out_len += write(1, s, i);	//spre
	}
	return (out_len);
}

int	format_di(int n, t_flags *flags)
{
	bool		is_negative;
	t_va		va_s;
	t_va		va_prefix;

	is_negative = n < 0;
	if (is_negative)
		va_s = utoa(- (unsigned int) n, _va_base_10);
	else
		va_s = utoa(n, _va_base_10);
	if (va_s.s == NULL)
		return (-1);
	if (va_s.s[0] == '0' && flags->precision == 0)
		va_s.len = 0;
	va_prefix.len = ((flags->blank || flags->plus) && !is_negative) || is_negative;
	va_prefix.s = NULL;
	if (va_prefix.len)
	{
		va_prefix.s = malloc(va_prefix.len + 1);
		if (va_prefix.s == NULL)
		{
			free(va_s.s);
			return (-1);
		}
		va_prefix.s[va_prefix.len] = 0;
		va_prefix.s[0] = (flags->blank * ' ' + flags->plus * '+') * !is_negative + is_negative * '-';
	}
	return (print_decimal(va_s, va_prefix, flags));
}

int	format_u(unsigned int n, t_flags *flags)
{
	t_va	va_s;

	va_s = utoa(n, _va_base_10);
	if (va_s.s == NULL)
		return (-1);
	return (print_decimal(va_s, (t_va) {.s = NULL, .len = 0}, flags));
}

int	format_hex(unsigned long long n, char type, bool caps, t_flags *flags)
{
	t_va	va_s;
	t_va	va_prefix;
	t_va	va_base;

	if (type == 'p' && n == 0)
		return format_s("(nil)", flags);
	va_base = _va_base_hex;
	if (caps)
		va_base = _va_base_HEX;
	va_s = utoa(n, va_base);
	if (va_s.s == NULL)
		return (-1);
	va_prefix.s = NULL;
	va_prefix.len = flags->hash * (n != 0) * 2;
	if (n == 0 && flags->precision == 0)
		va_s.len = 0;
	if (va_prefix.len)
	{
		va_prefix.s = malloc(2);
		if (va_prefix.s == NULL)
		{
			free(va_s.s);
			return (-1);
		}
		va_prefix.s[0] = '0';
		va_prefix.s[1] = caps * 'X' + !caps * 'x';
	}
	return (print_decimal(va_s, va_prefix, flags));
}
