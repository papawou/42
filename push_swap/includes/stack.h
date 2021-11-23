#ifndef STACK_H
# define STACK_H

typedef struct s_stack_elem
{
	int									value;
	struct s_stack_elem	*next;
	struct s_stack_elem	*prev;
} t_stack_elem;

typedef struct	s_stack
{
	t_stack_elem *head;
	t_stack_elem *tail;
	unsigned int size;
} t_stack;

t_stack_elem	*create_elem(int value);
void stack_rpush(t_stack *stack, t_stack_elem *elem);
void					stack_push(t_stack *stack, t_stack_elem *elem);
void swap(t_stack *stack, t_stack_elem *elem1, t_stack_elem *elem2);

#endif