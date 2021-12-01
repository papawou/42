#ifndef STACK_GETTERS_H
#define STACK_GETTERS_H

#include "stack/stack.h"

t_stack_elem *elem_by_index(t_stack *A, unsigned int idx, bool tail_start);
unsigned int index_by_elem(t_stack_elem *elem, bool tail_start);

#endif