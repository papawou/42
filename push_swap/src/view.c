#include "stack.h"
#include <stdint.h>
#include <stdio.h>
#include "stack_hist.h"
#include <stdbool.h>
#include <stack_cmd.h>

char	*get_move_txt(enum e_move move)
{
	if (move == SA)
		return "SA";
	if (move == SB)
		return "SB";
	if (move == PA)
		return "PA";
	if (move == PB)
		return "PB";
	if (move == RA)
		return "RA";
	if (move == RRA)
		return "RRA";
	if (move == RB)
		return "RB";
	if (move == RRB)
		return "RRB";
	if (move == RR)
		return "RR";
	if (move == RRR)
		return "RRR";
	return "!!!!MOVE_TXT_ERROR";
}

void print_hist_line(t_stack_hist *hist)
{
	size_t i = hist->len;

	printf("h :");
	while (i--)
		printf(" % 5d", hist->tab[i]->value);
	printf("\n");
}

void print_hists_line(t_stack_hist *A, t_stack_hist *B)
{
		size_t i = A->len;

	printf("hh:");
	while (i--)
		printf(" % 5d", A->tab[i]->value);
	printf(" | ");
	i = B->len;
	while(i--)
		printf(" % 5d", B->tab[i]->value);
	printf("\n");
}

void print_stack(t_stack *s, bool as_line)
{
	t_stack_elem *tmp;

	tmp = s->head;
	if (as_line)
			printf("s :");
	while (tmp)
	{
		if (as_line)
			printf(" % 5d", tmp->value);
		else
			printf(" %1.d%1.d %4d |\n",  s->tail == tmp, (s->head == tmp) * 2, tmp->value);
		tmp = tmp->prev;
	}
	printf("\n");
}

void print_stacks_line(t_stack *sA, t_stack *sB)
{
	t_stack_elem *tmp;

	tmp = sA->head;
	printf("ss:");
	while (tmp)
	{
		printf(" % 5d", tmp->value);
		tmp = tmp->prev;
	}
	printf(" | ");
	if (sB != NULL)
	{
		tmp = sB->head;
		while (tmp)
		{
			printf(" % 5d", tmp->value);
			tmp = tmp->prev;
		}
	}
	printf("\n");
}

void print_stacks(t_stack *sA, t_stack *sB)
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
