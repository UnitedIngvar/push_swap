#include "sort.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = stack->top_index;
	printf("head:	%zi\n", stack->head.value);
	printf("stack:	");
	while (i >= 0)
	{
		printf("%zi	", stack->array[i--].value);
	}
	printf("\n");
	sleep(1);
}

static int	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int64_t	fastest_index;
	int64_t	index;
	int64_t	instruction;

	fastest_index = 0;
	index = stack_b->top_index;
	while (index >= 0)
		if (stack_b->array[index].score <= stack_b->array[fastest_index].score)
			fastest_index = index;
	execute_push(stack_a, stack_b, fastest_index);
}

static int	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_specs	specials;
	int64_t	*sorted_array;

	sorted_array = get_sorted_array(stack_a->array, stack_a->top_index + 1);
	specials = find_special_values(sorted_array, stack_a->top_index + 1);
	while (stack_a->top_index > 1)
	{
		if (stack_a->head.value != specials.min && \
		stack_a->head.value != specials.max)
		{
			stack_pb(stack_a, stack_b);
			if (stack_b->head.value > specials.mid)
				stack_rb(stack_b);
		}
		else
			stack_ra(stack_a);
	}
	return (1);
}

int	full_sort(t_stack *stack_a, t_stack *stack_b)
{
	push_to_b(stack_a, stack_b);

	while (stack_b->top_index > -1)
	{
		clear_scores(stack_a, stack_b);
		assign_scores(stack_a, stack_b);
		push_to_a(stack_a, stack_b);
	}
}
