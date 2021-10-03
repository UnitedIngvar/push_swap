#include "sort.h"
#include "stdio.h"
#include <stdio.h>

void	sort_two_nums(t_stack *stack, bool is_descending)
{
	if (stack->top_index == 0)
		return ;
	if (stack->top_index != 1)
		return ; //error
	if (stack->array[0] > stack->array[1])
	{
		if (is_descending)
			return ;
		else
			stack_rb(stack);
	}
}

void	sort_three_nums_asc(t_stack *stack)
{
	ssize_t	*sorted_array;

	if (stack->top_index != 2)
		return ; //error
	sorted_array = get_sorted_array(stack->array, 3);
	printf("%zi	%zi	%zi\n", sorted_array[0], sorted_array[1], sorted_array[2]);
	if (stack->array[2] == sorted_array[0])
		if (stack->array[1] == sorted_array[2])
			stack_sa(stack);
	if (stack->array[2] == sorted_array[2])
	{
		if (stack->array[1] == sorted_array[0])
			stack_ra(stack);
		else
			stack_sa(stack);
	}
	if (stack->array[2] == sorted_array[1])
	{
		if (stack->array[1] == sorted_array[2])
			stack_rra(stack);
		else
			stack_sa(stack);
	}
}

static void merge_stacks(t_stack stack_a, t_stack stack_b)
{
	if (stack_b->array[stack->top_index])
}

int	mini_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return (1);
	if (stack_a->top_index < 2)
	{
		sort_two_nums(stack_a, false);
		return ;
	}
	if (stack_a->top_index == 2)
	{
		sort_three_nums_asc(stack_a);
		return ;
	}
	while (stack_a->top_index > 2)
		stack_pb(stack_a, stack_b);
	sort_two_nums(stack_b, true);
	sort_three_nums_asc(stack_a);
	return (1);
}

int	main(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->array = malloc(sizeof(ssize_t) * 3);
	stack->array[0] = 1;
	stack->array[1] = 2;
	stack->array[2] = 3;
	stack->top_index = 2;
	printf("%zi	%zi	%zi\n", stack->array[2], stack->array[1], stack->array[0]);
	sort_three_nums_asc(stack);
	printf("%zi	%zi	%zi\n", stack->array[2], stack->array[1], stack->array[0]);
}
