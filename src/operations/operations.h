#ifndef OPERATIONS_COMMON_H
# define OPERATIONS_COMMON_H
# include "push_swap.h"

void stack_push(t_stack *stack_from, t_stack *stack_to);
void stack_swap(t_stack *stack);
void stack_rotate(t_stack *stack_b);
void stack_rotate_reverse(t_stack *stack);

#endif
