#include <stdlib.h>
#include <stdbool.h>
#include "stack_hist.h"
#include "stack.h"


t_stack_hist	*stack_to_hist(t_stack *stack)
{
	t_stack_hist *hist;
	t_stack_elem 	*tmp;
	size_t	i;

	hist = (t_stack_hist *) malloc(sizeof(t_stack_hist));
	hist->len = stack->size;

	hist->tab = (t_stack_elem **) malloc(sizeof(t_stack_elem *) * hist->len);
	tmp = stack->tail;
	i = 0;
	while (tmp)
	{
		hist->tab[i++] = tmp;
		tmp = tmp->next;
	}

	return (hist);
}

void hist_to_stack(t_stack *stack, t_stack_hist *hist)
{
	size_t i;
	t_stack_elem *tmp;

	stack->size = hist->len;
	
	if (stack->size == 0)
	{
		stack->tail = NULL;
		stack->head = NULL;
		free(hist);
		return ;
	}

	stack->tail = hist->tab[0];
	stack->tail->prev = NULL;
	stack->tail->next = NULL;
	stack->tail->stack = stack;
	
	stack->head = hist->tab[hist->len - 1];
	stack->head->next = NULL;

	i = 1;
	while (i < hist->len)
	{
		tmp = hist->tab[i];
		tmp->stack = stack;
		tmp->prev = hist->tab[i - 1];
		tmp->prev->next = tmp;
		++i;
	}

	free(hist->tab);
	free(hist);
}

bool compare_hist_stack(t_stack *stack, t_stack_hist *hist)
{
	t_stack_elem *tmp;
	size_t i;

	if (stack->size != hist->len)
		return false;
	if (stack->size == 0 && hist->len == 0)
		return true;
	
	if (stack->tail != hist->tab[0]) //check_tail
		return false;
	if (stack->head != hist->tab[hist->len - 1]) //check_head
		return false;

	i = hist->len;
	tmp = stack->head;
	while (i--)
	{
		if (tmp != hist->tab[i])
			return false;
		tmp = tmp->prev;
	}
	return true;
}