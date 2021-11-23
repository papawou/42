#include "stack.h"
#include <stdint.h>
#include "stdio.h"

void print_stack(t_stack *sA, t_stack *sB)
{
	t_stack_elem *tmpA;
	t_stack_elem *tmpB;
	int size_max;
	int size_min;
	int Aprint;
	int Bprint;

	tmpA = sA->head;
	tmpB = sB->head;
	printf("-----------------\n");
	
	Aprint = sA->size >= sB->size; 
	if (sA->size > sB->size)
	{
		Bprint = 0;
		size_max = sA->size;
		size_min = sB->size;
	}
	else
	{
		Bprint = 1;
		size_max = sB->size;
		size_min = sA->size;
	}

	while (size_max)
	{
		if (size_max-- <= size_min)
		{
			Aprint = 1;
			Bprint = 1;
		}

		if (Aprint && tmpA)
			printf(" %1.d%1.d %4d |",  sA->tail == tmpA, (sA->head == tmpA) * 2, tmpA->value);
		else
			printf("         |");
		if (Bprint && tmpB)
			printf(" %1.d%1.d %4d\n", sB->tail == tmpB, (sB->head == tmpB) * 2, tmpB->value);
		else
			printf("\n");
		
		if (Aprint && tmpA)
			tmpA = tmpA->prev;
		if (Bprint && tmpB)
			tmpB = tmpB->prev;
	}
	printf("-----------------\n");
}