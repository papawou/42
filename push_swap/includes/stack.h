#ifndef STACK_H
# define STACK_H

#include <stdbool.h>

typedef struct s_stack t_stack;

typedef struct s_stack_elem
{
	int									value;
	t_stack							*stack;

	struct s_stack_elem	*next;
	struct s_stack_elem	*prev;
} t_stack_elem;

struct	s_stack
{
	t_stack_elem *head;
	t_stack_elem *tail;
	unsigned int size;
};

t_stack *create_stack();
t_stack_elem	*create_elem(int value);
void stack_rpush(t_stack *stack, t_stack_elem *elem);
void	stack_push(t_stack *stack, t_stack_elem *elem);
void stack_remove(t_stack_elem *A);
bool stack_is_sorted(t_stack *stack);

#endif