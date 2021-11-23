#include <stdlib.h>
#include "stack.h"

static int	ft_atoi(char *s)
{
	int				nb;
	short int	sign;

	nb = 0;
	sign = 1;
	if (s[0] == '-' && ++s)
		sign = -1;
	while (*s)
	{
		nb *= 10;
		nb += (*s - '0');
		++s;
	}
	return (nb * sign);
}

t_stack *parse_args(char *args[], size_t len)
{
	t_stack *s;
	size_t i;

	i = 0;
	s = create_stack();
	while (i < len)
		stack_push(s, create_elem(ft_atoi(args[i++]))); //a f d e f --> f e d f a
	return (s);
}