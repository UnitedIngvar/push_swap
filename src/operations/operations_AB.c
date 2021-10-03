#include "operations.h"

void stack_ss(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
	write(1, "ss\n", 3);
}

//RR принимает стек А и стек В
void stack_rr(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_a);
	stack_rotate(stack_b);
	write(1, "rr\n", 3);
}

//RRR принимает стек A и стек B
void stack_rrr(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate_reverse(stack_a);
	stack_rotate_reverse(stack_b);
	write(1, "rrr\n", 4);
}
