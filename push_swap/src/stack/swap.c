#include "stack/stack.h"

// A -next> <prev- B
static void swap_adj(t_stack_elem *A, t_stack_elem *B)
{
	B->prev = A->prev;
	A->next = B->next;

	B->next = A;
	A->prev = B;
}

//AB -next> ... <prev- AB
static void swap_dist(t_stack_elem *A, t_stack_elem *B)
{
	t_stack_elem *tmp;

	tmp = A->prev;
	A->prev = B->prev;
	B->prev = tmp;

	tmp = A->next;
	A->next = B->next;
	B->next = tmp;
}

static void swap_prop(t_stack_elem *A)
{
	if (!A->prev)
		A->stack->tail = A;
	else
		A->prev->next = A;
	if (!A->next)
		A->stack->head = A;
	else
		A->next->prev = A;
}

// [ AB ] [ AB ]
static void sswap(t_stack_elem *A, t_stack_elem *B)
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
	else if (A->next == B) // A -next> B
		swap_adj(A, B);
	else if (A->prev == B) // B -next> A
		swap_adj(B, A);
	else
		swap_dist(A, B); // AB -> ... AB
	swap_prop(A);
	swap_prop(B);
}