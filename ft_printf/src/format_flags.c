#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>

#include "headers/ft_utils.h"
#include "headers/t_flags.h"

char *insert_pad(const char *s, size_t s_start, size_t s_len, size_t pad, char c)
{
	size_t	out_len;
	char		*out;
	size_t	i;

	i = 0;
	out_len = s_len + pad;
	out = malloc(out_len + 1);
	out[out_len] = 0;

	while (i < s_start && ++i) //start string
		out[i - 1] = s[i - 1];
	while (i < s_start + pad) //pad
		out[i++] = c;
	while (i < out_len && ++i) //end string
		out[i - 1] = s[i - pad - 1];
	return (out);
}

char *format_width(const char *s, const size_t s_len, const size_t prefix_len, const t_flags *flags)
{
	char		c;
	size_t	pad;
	size_t	out_len;
	char		*out;
	size_t	i;
	
	c = flags->zero * '0' + !flags->zero * ' ';
	pad = 0;
	if (0 <= flags->width && (s_len + prefix_len) < (size_t) flags->width) //need pad
		pad = flags->width - (s_len + prefix_len);
	i = 0;
	out_len = s_len + prefix_len + pad;
	out = malloc(out_len + 1);
	out[0] = 'a';
	out[out_len] = 0;
	while (i < flags->minus * s_len && ++i) //start string
		out[i - 1] = s[i - 1];
	while (i < flags->minus * s_len + pad + prefix_len && ++i) //pad
		out[i - 1] = c;
	while (i < out_len && ++i) //end string
		out[i - 1] = s[i - pad - prefix_len - 1];
	return (out);
}

size_t	format_precision_d(char *s, size_t s_len, char **dst, int precision)
{
	size_t	digit_s;

	if (precision == 0 && *s == '0')
		return 0; //nothing to output
	digit_s = s_len - (s[0] == '-');
	if (0 <= precision && digit_s < (size_t) precision) //need_pad
	{
		*dst = insert_pad(s, s_len - digit_s, s_len, precision - digit_s, '0');
		return (s_len + precision - digit_s);
	}
	*dst = s;
	return (s_len);
}

size_t format_precision_s(char *s, char **dst, int precision)
{
	size_t len;

	len = ft_strlen(s);
	if (0 <= precision && (size_t) precision < len) //need crop
		len = ft_strncpy_len(s, len, dst, precision);
	else
		*dst = s;
	return (len);
}