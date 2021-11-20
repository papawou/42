#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>
#include <unistd.h>

#include "t_flags.h"
#include "t_va.h"

bool ft_strchr_bool(const char *src, const char c)
{
	while(*src)
		if (*src++ == c)
			return (true);
	return (false);
}

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while(*s && ++s)
		++i;
	return (i);
}

bool ft_isdigit(const char c)
{
	return ('0' <= c && c <= '9');
}

char *atoi_s(const char *s, int *nb)
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

int	count_digits(unsigned long long nb, const int base_len)
{
	int	i;

	i = 1;
	while (nb > (uintptr_t) base_len && ++i)
		nb /= base_len;
	return (i);
}

void fill_utoa(unsigned long long nb, t_va va_out, const t_va va_base)
{
	while (va_out.len && va_out.len--)
	{
		va_out.s[va_out.len] = va_base.s[nb%va_base.len];
		nb /= va_base.len;
	}
}

t_va	utoa(const unsigned long long nb, const t_va va_base)
{
	t_va	va_out;

	va_out.len = count_digits(nb, va_base.len);
	va_out.s = malloc(va_out.len + 1);
	if (va_out.s == NULL)
		return (t_va) {.s = NULL, .len = -1};
	va_out.s[va_out.len] = 0;
	fill_utoa(nb, va_out, va_base);
	return (va_out);
}