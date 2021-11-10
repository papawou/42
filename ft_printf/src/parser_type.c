#include <stdlib.h>
#include <unistd.h>
#include "headers/parser_format.h"

/*
#:
	for non zero values:
		x : 0x...
		X : 0X...
0:
	if '-' flag //ignore '0'
	pad left with 0 instaed of blank
	if precision exist //ignore '0'
-:
	//overrides '0'
	right pad with
' ':
	add space before positive number or empty stirng produced by a signed conversion
+:
	//overrides ' '
	place sign in front of signed conversion

*/

char *parse_c(unsigned char c, t_flags *flags)
{
	write(1, &c, 1);
}

char *parse_s(char *s, t_flags *flags)
{
	size_t len = ft_strlen(s);
	size_t i = 0;

	if (len < flags->max)
		flags->max = len;
	if (flags->min < flags->max)
		flags->min = flags->max;
	
	if (flags->justify_left)
	{
		while (i < flags->min - flags->max && ++i) //pad
			write(1, " ", 1);
		write(1, s, flags->max); //write s
	}
	else
	{
		write(1, s, flags->max); //write s
		while (i < flags->min - flags->max && ++i) //pad
			write(1, " ", 1);
	}
	return (s + flags->min);
}

char *parse_di(int n, t_flags *flags)
{
	char *s  = q_itoa(n, "0123456789");
	if (s == NULL)
		return (NULL);
	size_t s_len = ft_strlen(s);
	
	free(s);
}

char *parse_p(void *p, t_flags *flags)
{
	char *s = q_utoa(p, "0123456789abcdef");
	if (s == NULL)
		return NULL;
	format_s_pad(s, pad);
	free(s);
}


char *parse_u(unsigned int *n)
{
	char *s  = q_itoa(n, "0123456789");
	if (s == NULL)
		return (NULL);
	format_s_pad(s, pad);
	free(s);
}

char *parse_x(unsigned int n, t_pad *pad)
{
	char *s  = q_utoa(n, "0123456789abcdef");
	if (s == NULL)
		return (NULL);
	format_s_pad(s, pad);
	free(s);
}

char *parse_X(unsigned int n, t_pad *pad)
{
	char *s = q_utoa(n, "0123456789ABCDEF")
		if (s == NULL)
			return (NULL);
	format_s_pad(s, pad);
	free(s);
}

char *parse_word(char *s, t_page **page)
{
	size_t	len;
	char		*out;

	len = 0;
	while (s[len] && s[len] != '%')
		++len;
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	ft_lstadd_front(page, ft_lst_new(ft_strncpy(out, s, len)));
	return (s + len);
}

#include <stdarg.h>
char *parse_type(const char *s, va_list ap, t_flags *flags)
{
	if (*s == 'c')
		return parse_c(va_arg(ap, unsigned char), flags);
	else if (*s == 's')
		return parse_s(va_arg(ap, char *), flags);
	else if (*s == 'p')
		return parse_p(va_arg(ap, void *), flags);
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