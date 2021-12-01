#ifndef HIST_H
#define HIST_H

#include <sys/types.h>

#include "stack/stack.h"

typedef struct s_stack_hist
{
	t_stack_elem	**tab;
	size_t				len;
} t_stack_hist;

t_stack_hist	*stack_to_hist(t_stack *stack);
void hist_to_stack(t_stack *stack, t_stack_hist *hist);
bool compare_hist_stack(t_stack *stack, t_stack_hist *hist);

#endif