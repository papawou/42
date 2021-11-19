#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_utils.h"
#include "t_flags.h"

size_t	print_c(const char c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		++i;
	}
	return (i);
}

size_t	print_decimal_minus(t_va va_s, t_va va_prefix, t_flags *flags)
{
	size_t	out_len;
	size_t precision;

	out_len = 0;
	precision = 0;
	if (0 < flags->precision)
		precision = (va_s.len < (size_t) flags->precision) * (flags->precision - va_s.len);
	out_len += write(1, va_prefix.s, va_prefix.len); //prefix
	out_len += print_c('0', precision); //precision
	out_len += write(1, va_s.s, va_s.len); // s
	out_len += print_c(' ', (out_len < (size_t) flags->width) * (flags->width - out_len)); //pad ' '
	return (out_len);
}

size_t	print_decimal_zero(t_va va_s, t_va va_prefix, t_flags *flags)
{
	size_t	out_len;
	size_t	pad;

	pad = 0;
	if ((va_s.len + va_prefix.len) < (size_t) flags->width)
		pad = (flags->width - va_s.len - va_prefix.len);
	out_len = 0;
	out_len += write(1, va_prefix.s, va_prefix.len); //prefix
	out_len += print_c('0', pad); //pad 0
	out_len += write(1, va_s.s, va_s.len); //s
	return (out_len);
}

size_t	print_decimal_right(t_va va_s, t_va va_prefix, t_flags *flags)
{
	size_t	out_len;
	size_t	width;
	size_t	precision;

	precision = 0;
	if (0 < flags->precision)
		precision = (va_s.len < (size_t) flags->precision) * (flags->precision - va_s.len);
	width = va_s.len + va_prefix.len + precision;
	out_len = 0;
	out_len += print_c(' ', (width < (size_t) flags->width) * (flags->width - width)); //pad ' '
	out_len += write(1, va_prefix.s, va_prefix.len); //prefix
	out_len += print_c('0', precision); //precision
	out_len += write(1, va_s.s, va_s.len); //s
	return (out_len);
}

size_t print_decimal(t_va va_s, t_va va_prefix, t_flags *flags)
{
	size_t	out_len;

	if (flags->minus) //left
		out_len = print_decimal_minus(va_s, va_prefix, flags);
	if (flags->zero) //no precision
		out_len = print_decimal_zero(va_s, va_prefix, flags);
	else //right
		out_len = print_decimal_right(va_s, va_prefix, flags);
	if (va_prefix.s)
		free(va_prefix.s);
	free(va_s.s);
	return (out_len);
}