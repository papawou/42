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

	if (flags->hash || flags->blank || flags->plus || flags->zero)
		return (NULL); // flags incorrect for type
	curr_len = format_precision_s(s, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, 0, flags, false);
	if (s_precision != s)
		free(s_precision);
	return (out);
}

char *format_di(int n, t_flags *flags)
{
	bool		n_negative;

	char		*out;
	char		*s;
	char		*s_precision;
	size_t	curr_len;

	curr_len = q_itoa(n, _base_10, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
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

	curr_len = q_utoa(n, _base_10, &s);
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
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
	curr_len = format_precision_d(s, curr_len, &s_precision, flags->precision);
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
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
	out = format_width(s_precision, curr_len, flags, flags->zero && flags->precision == -1 && !flags->minus);
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
		return format_c((unsigned char) va_arg(ap, int), flags);
	else if (*s == 's')
		return format_s(va_arg(ap, char *), flags);
	else if (*s == 'p')
		return format_p(va_arg(ap, uintptr_t), flags);
	else if (*s == 'd' || *s == 'i')
		return format_di(va_arg(ap, int), flags);
	else if (*s == 'u')
		return format_u(va_arg(ap, unsigned int), flags);
	else if (*s == 'x')
		return format_x(va_arg(ap, int), flags);
	else if (*s == 'X')
		return format_X(va_arg(ap, int), flags);
	else if(*s == '%')
	{
		write(1, "%", 1);
		return ((char *) s + 1);
	}
	return (NULL);
}

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void)
{
	//t_flags flags = {.blank = 0, .hash = 0, .plus = 0, .zero = 0, .minus = 1, .width = 7, .precision = -1};
	//printf("%s", format_di(-123, &flags));
	printf("%0s", "");

	return 0;
}