#include "operations.h"

void stack_sa(t_stack *stack)
{
	stack_swap(stack);
	write(1, "sa\n", 3);
}

void stack_pa(t_stack *stack_b, t_stack *stack_a)
{
	stack_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void stack_ra(t_stack *stack)
{
	stack_rotate(stack);
	write(1, "ra\n", 3);
}

void stack_rra(t_stack *stack)
{
	stack_rotate_reverse(stack);
	write(1, "rra\n", 4);
}
