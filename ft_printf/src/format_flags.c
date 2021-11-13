#include <stdbool.h>
#include <sys/types.h>

#include "headers/t_flags.h"

char *insert_pad(char *s, size_t s_start, size_t s_len, size_t pad, char c)
{
	size_t	out_len;
	char		*out;
	size_t	i;

	i = 0;
	out_len = s_len + pad;
	out = malloc(out_len + 1);
	while (i < s_start && ++i)
		out[i - 1] = s[i - 1];
	while (i < pad && ++i)
		out[i - 1] = c;
	while (i < out_len && ++i)
		out[i - 1] = s[i - pad - 1];
	return (out);
}

char *format_width(const char *s, const size_t s_len, const t_flags *flags, const bool print_zero)
{
	char		c;
	char		*out;
	size_t	i;
	size_t	out_len;
	
	if (print_zero)
		c = '0';
	else
		c = ' ';
	if (s_len < flags->width)
		out_len = flags->width;
	else
		out_len = s_len;
	//tothink use format_pad() func ?
	out = malloc(out_len + 1);
	out[out_len] = 0;
	i = 0;
	while (i < out_len - s_len) //pad
		out[flags->minus * s_len + i++] = c;
	while (i < out_len && out_len--) //strncpy
		out[out_len - flags->minus * i] = s[out_len - i];
	return (out);
}

size_t	format_precision_d(char *s, size_t s_len, char **dst, int precision)
{
	size_t	digit_s;

	if (precision == 0)
		//skip 0value

	digit_s = s_len - (s[0] == '-');
	if (digit_s < precision) //need_pad
	{
		*dst = insert_pad(s, s + (s_len - digit_s), s_len, precision - digit_s, '0');
		return (s_len + precision - digit_s);
	}
	*dst = s;
	return (s_len);
}

size_t format_precision_s(char *s, char **dst, int precision)
{
	size_t len;

	len = ft_strlen(s);
	if (-1 < precision && precision < len) //need crop
		len = ft_strncpy_len(s, len, dst, precision);
	else
		*dst = s;
	return (len);
}