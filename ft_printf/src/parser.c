#include <stdbool.h>
#include <stdarg.h>

#include <stddef.h>
#include "t_flags.h"
#include "ft_utils.h"

const char *parse_pad(const char *s, t_flags *flags)
{
	if(*s == '*' && ++s) //min width
	{}
	else if (ft_isdigit(*s))
		s = atoi_s(s, &flags->width);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
	if (*s == '.' && ++s) //precision
	{
		flags->precision = 0;
		if (*s == '*' && ++s)
		{}
		else if (ft_isdigit(*s))
			s = atoi_s(s, &flags->precision);
		if (flags->precision < 0)
			flags->precision = 0;
	}
	flags->zero = (flags->zero && !flags->minus && flags->precision == -1);
	flags->blank = flags->blank && !flags->plus;
	return (s);
}

const char *parse_flags(const char *s, t_flags *flags)
{
	while (*s)
	{
		if (*s == '-' && !flags->minus)
			flags->minus = true;
		else if (*s == '+' && !flags->plus)
			flags->plus = true;
		else if (*s == ' ' && !flags->blank)
			flags->blank = true;
		else if (*s == '0' && !flags->zero)
			flags->zero = true;	
		else if (*s == '#' && !flags->hash)
			flags->hash = true;
		else if (ft_strchr_bool("-+ 0#", *s)) //flag happen twice tothink ?use bitenum
			return (NULL);
		else
			break;
		++s;
	}
	return (s);
}

char	*parse_type(const char *s, va_list ap, t_flags *flags, size_t *out_len)
{
	ssize_t	out;

	out = -1;
	if (*s == 'c')
		out = format_c((unsigned char) va_arg(ap, int));
	else if (*s == 's')
		out = format_s(va_arg(ap, char *), flags);
	else if (*s == 'd' || *s == 'i')
		out = format_di(va_arg(ap, int), flags);
	else if (*s == 'u')
		out = format_u(va_arg(ap, unsigned int), flags);
	else if (*s == 'p' || *s == 'x' || *s == 'X')
		out = format_hex(va_arg(ap, uintptr_t), *s == 'X', (*s == 'p' || flags->hash), flags);
	else if(*s == '%')
		out = write(1, "%", 1);
	if (out < 0)
		return (NULL);
	out_len += out;
	return (s + 1);
}