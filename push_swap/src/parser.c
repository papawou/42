#include <stdlib.h>
#include "stack/stack.h"

void set_idx_target(t_stack *A)
{
	t_stack_elem *tmp_elem;
	t_stack_elem *tmp_target;

	tmp_elem = A->head;
	while(tmp_elem)
	{
		tmp_target = A->head;
		while (tmp_target)
		{
			if (tmp_elem->value < tmp_target->value)
				++tmp_target->idx_target;
			tmp_target = tmp_target->prev;
		}
		tmp_elem = tmp_elem->prev;
	}
}

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
		stack_push(s, create_elem(ft_atoi(args[i++])));
	set_idx_target(s);
	return (s);
}

t_stack *parse_int_args(int args[], size_t len)
{
	t_stack *s;
	size_t i;

	i = 0;
	s = create_stack();
	while (i < len)
		stack_push(s, create_elem(args[i++]));
	set_idx_target(s);
	return (s);
}
