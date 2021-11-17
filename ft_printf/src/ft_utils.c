#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

void ft_putstr(char *s)
{
	size_t i;
	i = 0;
	while(s[i])
		write(1, s + i++, 1);
}

bool ft_strchr_bool(const char *src, const char c)
{
	while(*src)
		if (*src == c)
			return (true);
	return (false);
}

size_t	ft_strncpy_len(const char *src, size_t src_len, char **dst, size_t n)
{
	if (src_len < n)
		n = src_len;
	else
		src_len = n;
	*dst = malloc(n + 1);
	(*dst)[n] = 0;
	while (src_len && src_len--)
		(*dst)[src_len] = src[src_len];
	return (n);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while(*s && ++s)
		++i;
	return (i);
}

bool ft_isdigit(const char c)
{
	return ('0' <= c && c <= '9');
}

char *q_atoi_s(const char *s, int *nb) //tothink negative value ?
{
	*nb = 0;
	while (ft_isdigit(*s))
	{
		*nb *= 10;
		*nb += *s - '0';
		++s;
	}
	return ((char *) s);
}

unsigned int count_digits(uintptr_t nb, const int len_base)
{
	size_t	i;

	i = 1;
	while (nb > (uintptr_t) len_base && ++i)
		nb /= len_base;
	return (i);
}

void ft_fill_itoa(uintptr_t nb, char *dst, size_t digit_count, const char *base, const size_t base_len)
{
	while (digit_count && digit_count--)
	{
		dst[digit_count] = base[nb%base_len];
		nb = nb/base_len;
	}
}

size_t	q_itoa(const int nb, const char *base, char **dst)
{
	unsigned int	_nb;
	size_t				base_len;
	size_t				out_len;

	out_len = 0;
 	base_len = ft_strlen(base);
	if (nb < 0)
	{
		_nb = -nb;
		out_len = 1;
	}
	else
		_nb = nb;
	out_len += count_digits(_nb, base_len);
	*dst = malloc(out_len + 1);
	(*dst)[out_len] = 0;
	if (nb < 0)
	{
		(*dst)[0] = '-';
		ft_fill_itoa(_nb, *dst + 1, out_len - 1, base, base_len);
	}
	else
		ft_fill_itoa(_nb, *dst, out_len, base, base_len);
	return (out_len);
}

size_t	q_utoa(const uintptr_t nb, const char *base, char **dst)
{
	size_t base_len;
	size_t dst_len;

	base_len = ft_strlen(base);
	dst_len = count_digits(nb, base_len);
	*dst = malloc(dst_len + 1);
	(*dst)[dst_len] = 0;
	ft_fill_itoa(nb, *dst, dst_len, base, base_len);
	return (dst_len);
}