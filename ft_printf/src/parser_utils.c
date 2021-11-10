#include <stdbool.h>
#include <sys/types.h>

bool ft_strchr_bool(char *src, char c)
{
	while(*src)
		if (*src == c)
			return (true);
	return (false);
}

size_t ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while(*s++)
		++i;
	return (i);
}

bool ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

char *q_atoi(char *s, unsigned int *nb)
{
	unsigned int nb;

	*nb = 0;
	while (ft_isdigit(*s))
	{
		*nb *= 10;
		*nb += *s - '0';
		++s;
	}
	return (s);
}

size_t count_digits(unsigned int nb, int ref)
{
	size_t i = 0;
	while (nb > ref)
	{
		nb /= ref;
		i++;
	}
	return (i);
}

char *ft_itoa(unsigned int nb, char *out, const char *alpha, const size_t len)
{
	if (nb > len)
		out = ft_itoa(nb, out, alpha, len);
	*out = alpha[nb%len];
	return ++out;
}

char *q_itoa(const int nb, const char *alpha)
{
	unsigned int _nb;
	size_t alpha_len = ft_strlen(alpha);
	size_t out_len = 0;

	if (nb < 0)
	{
		_nb = -nb;
		out_len = 1;
	}
	else
		_nb = nb;
	out_len += count_digits(_nb, alpha_len);

	char *out = malloc(out_len + 1);
	out[out_len] = 0;
	if (nb < 0)
	{
		out[0] = '-';
		ft_itoa(_nb, out + 1, alpha, alpha_len);
	}
	else
		ft_itoa(_nb, out, alpha, alpha_len);
	return out;
}

char *q_utoa(const unsigned int nb, const char *alpha)
{
	size_t alpha_len = ft_strlen(alpha);
	size_t out_len = count_digits(nb, alpha_len);
	char *out = malloc(out_len + 1);
	out[out_len] = 0;
	ft_itoa(nb, out, alpha, alpha_len);
	return out;
}