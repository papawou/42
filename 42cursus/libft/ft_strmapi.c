#include <stdlib.h>
#include <libft.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*out;
	size_t	s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	out = malloc(s_len + 1);
	if (!out)
		return (NULL);
	out[s_len] = 0;
	while (s_len--)
		out[s_len] = (*f)(s_len, s[s_len]);
	return (out);
}