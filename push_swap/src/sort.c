#include "stack_cmd.h"

void sort_2(t_stack *A, t_stack *B)
{
	if (A->head < A->tail)
		cmd_swap(A);
}

void sort_3(t_stack *A, t_stack *B)
{
	if (A->)
}

/*
//n2
1		2
2		1
		s
//n3
1		1
2		3
3		2
		rr/s
		s/r

2		2
1		3
3		1
s		rr

3		3
1		2
2		1
r		r/s
		s/rr

//n4
1		1							1				1		1		1
2		2							3				3		4		4
3		4							2				4		2		3
4		3							4				2		3		2
		pb						r				
		s/r rr/s			s
		pa						rr


*/