#include <stdbool.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

#include "t_flags.h"
#include "ft_utils.h"
#include "format_types.h"

void clean_type_flags(char c, t_flags *flags)
{
	if (c == 'p')
	{
		//flags->zero = 0;
		//flags->precision = -1;
		flags->hash = 1;
	}
	flags->zero = flags->zero && !flags->minus && flags->precision == -1;
	flags->blank = flags->blank && !flags->plus;
}

const char *parse_pad(const char *s, va_list ap, t_flags *flags)
{
	if (s == NULL)
		return (NULL);
	if(*s == '*' && ++s) //min width
		flags->width = va_arg(ap, int);
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
			flags->precision = va_arg(ap, int);
		else if (ft_isdigit(*s))
			s = atoi_s(s, &flags->precision);
		if (flags->precision < 0)
			flags->precision = -1;
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

const char	*parse_type(const char *s, va_list ap, t_flags *flags, size_t *out_len)
{
	int	out;

	out = -1;
	clean_type_flags(*s, flags);
	if (s == NULL)
		return (NULL);
	else if (*s == 'c')
		out = format_c((unsigned char) va_arg(ap, int), flags);
	else if (*s == 's')
		out = format_s(va_arg(ap, char *), flags);
	else if (*s == 'd' || *s == 'i')
		out = format_di(va_arg(ap, int), flags);
	else if (*s == 'u')
		out = format_u(va_arg(ap, unsigned int), flags);
	else if (*s == 'x' || *s == 'X')
		out = format_hex(va_arg(ap, unsigned int), *s, *s == 'X', flags);
	else if (*s == 'p')
		out = format_hex(va_arg(ap, uintptr_t), *s, false, flags);
	else if(*s == '%')
		out = write(1, "%", 1);
	if (out < 0)
		return (NULL);
	*out_len += out;
	return (s + 1);
}