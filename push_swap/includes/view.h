#ifndef VIEW_H
# define VIEW_H

#include "stack/stack.h"
#include "hist.h"
#include "cmd.h"

void print_stacks(t_stack *sA, t_stack *sB);
void print_hist_line(t_stack_hist *hist);
void print_stack(t_stack *s, bool as_line);
void print_stacks_line(t_stack *sA, t_stack *sB);
void print_hists_line(t_stack_hist *A, t_stack_hist *B);
char	*get_move_txt(enum e_move move);
void print_cmd(t_cmd *entry);
#endif