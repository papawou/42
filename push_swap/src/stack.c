#include <stdlib.h>

#include "stack.h"

t_stack_elem *create_elem(int value)
{
	t_stack_elem *elem;

	elem = malloc(sizeof(t_stack_elem));
	elem->value = value;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

//TAIL prev <<a>> <<1>> <<2>> <<b>> next HEAD
void stack_push(t_stack *stack, t_stack_elem *elem) //push to head
{
	if (stack->head)
	{
		elem->prev = stack->head;
		elem->prev->next = elem;
	}
	else
		stack->tail = elem;
	stack->head = elem;
}

void stack_rpush(t_stack *stack, t_stack_elem *elem) //push to tail
{
	if (stack->tail)
	{
		elem->next = stack->tail;
		elem->next->prev = elem;
	}
	else
		stack->head = elem;
	stack->tail = elem;
}

t_stack_elem *stack_remove(t_stack_elem *A)
{
	if (A->prev)
		A->prev->next = A->next;
	else
		A->stack->tail = A->next;
	if (A->next)
		A->next->prev = A->prev;
	else
		A->stack->head = A->prev;
	A->prev = NULL;
	A->next = NULL;
	A->stack = NULL;
	return (A);
}

// A -next> <prev- B
void swap_adj(t_stack_elem *A, t_stack_elem *B)
{
	B->prev = A->prev;
	A->next = B->next;

	B->next = A;
	A->prev = B;
}

//AB -next> ... <prev- AB
void swap_dist(t_stack_elem *A, t_stack_elem *B)
{
	t_stack_elem *tmp;

	tmp = A->prev;
	A->prev = B->prev;
	B->prev = tmp;

	tmp = A->next;
	A->next = B->next;
	B->next = tmp;
}

// [ AB ] [ AB ]
void sswap(t_stack_elem *A, t_stack_elem *B)
{
	void *tmp;

	tmp = A->next;
	A->next = B->next;
	B->next = tmp;
	tmp = A->prev;
	A->prev = B->prev;
	B->prev = tmp;
	tmp = A->stack;
	A->stack = B->stack;
	B->stack = tmp;
}

void swap(t_stack_elem *A, t_stack_elem *B)
{
	if (!A || !B)
		return ;
	if (A->stack != B->stack) //[ AB ] [ AB ]
		sswap(A, B);
	else if (A->next == B) // A-next> B
		swap_adj(A, B);
	else if (A->prev == B) // B -next> A
		swap_adj(B, A);
	else
		swap_dist(A, B); // AB -> ... AB
	if (!A->prev)
		A->stack->tail = A;
	if (!A->next)
		A->stack->head = A;
	if (!B->prev)
		B->stack->tail = B;
	if (!B->next)
		B->stack->head = B;
}


void move_s(t_stack *stack) //move two top
{
}