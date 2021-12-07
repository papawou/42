#ifndef STACK_GETTERS_H
#define STACK_GETTERS_H

#include "stack/stack.h"

t_stack_elem *elem_by_idx(t_stack *A, unsigned int idx, bool tail_start);
unsigned int idx_by_elem(t_stack_elem *elem, bool tail_start);
t_stack_elem *find_minus(t_stack *a);
t_stack_elem *find_max(t_stack *s);

#endif