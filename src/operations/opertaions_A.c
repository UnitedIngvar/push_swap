#include "push_swap.h"
#include "operations.h"

void stack_sb(t_stack *stack)
{
	stack_swap(stack);
	write(1, "sa\n", 3);
}

void stack_pb(t_stack *stack_b, t_stack *stack_a)
{
	stack_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void stack_rb(t_stack *stack)
{
	stack_rotate(stack);
	write(1, "ra\n", 3);
}

void stack_rrb(t_stack *stack)
{
	stack_rotate_reverse(stack);
	write(1, "rra\n", 4);
}
