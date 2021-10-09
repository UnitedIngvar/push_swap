#include "sort.h"
#include <stdio.h>
#include <limits.h>


void	print_stack(t_stack *stack)
{
	int i;

	i = stack->top_index;
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--]);
	}
	printf("\n");
}

static int	sort_two_nums(t_stack *stack)
{
	if (stack->top_index == 0)
		return (1);
	if (stack->top_index != 1)
		return (1);
	if (stack->array[0] < stack->array[1])
			stack_rb(stack);
}

static int	sort_three_nums_asc(t_stack *stack)
{
	ssize_t	*sorted_array;

	if (stack->top_index != 2)
		return (-1);
	sorted_array = get_sorted_array(stack->array, 3);
	int i = 0;
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
	return (1);
}

static void	push_rotate(t_stack *stack_b, t_stack *stack_a)
{
	stack_pa(stack_b, stack_a);
	stack_ra(stack_a);
}

static int	merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	beginning;
	bool	itered;

	itered = false;
	while(stack_b->top_index >= 0)
	{
		if (stack_b->array[stack_b->top_index] < stack_a->array[stack_a->top_index])
		{
			if (stack_b->array[stack_b->top_index] < beginning)
				beginning = stack_b->array[stack_b->top_index];
			push_rotate(stack_b, stack_a);
		}
		else
			stack_ra(stack_a);
		if (beginning == stack_a->array[stack_a->top_index] && itered)
			break;
		itered = true;
	}
	while (stack_b->top_index > -1)
		push_rotate(stack_b, stack_a);
	while (!is_sorted(stack_a))
		stack_ra(stack_a);
	return (1);
}

int	mini_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top_index < 2)
		return (sort_two_nums(stack_a));
	if (stack_a->top_index == 2)
		return (sort_three_nums_asc(stack_a));
	while (stack_a->top_index > 2)
		stack_pb(stack_a, stack_b);
	sort_two_nums(stack_b);
	sort_three_nums_asc(stack_a);
	return (merge_stacks(stack_a, stack_b));
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_a->array = malloc(sizeof(ssize_t) * 5);
	stack_a->array[0] = 5248;
	stack_a->array[1] = 346263;
	stack_a->array[2] = -45634;
	stack_a->array[3] = INT_MAX;
	stack_a->array[4] = INT_MIN;
	stack_a->top_index = 4;
	stack_a->length = 5;

	stack_b = malloc(sizeof(t_stack));
	stack_b->array = malloc(sizeof(ssize_t) * 5);
	stack_b->top_index = -1;
	stack_b->length = 5;

	printf("%zi	%zi	%zi	%zi	%zi\n", stack_a->array[4], stack_a->array[3], stack_a->array[2], stack_a->array[1], stack_a->array[0]);
	mini_sort(stack_a, stack_b);
	printf("%zi	%zi	%zi	%zi	%zi\n", stack_a->array[4], stack_a->array[3], stack_a->array[2], stack_a->array[1], stack_a->array[0]);
}
