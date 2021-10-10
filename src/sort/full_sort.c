#include "sort.h"
#include <stdio.h>
#include <limits.h>

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

static int	execute_push(t_stack *stack_a, t_stack *stack_b, ssize_t fstst_i)
{
	while (stack_b->array[fstst_i].score > 0)
	{
		if (stack_b->array[fstst_i].score_a > 0 && \
			stack_b->array[fstst_i].score_b > 0)
		{
			if (!stack_b->array[fstst_i].is_reversed_a && \
				!stack_b->array[fstst_i].is_reversed_b)
			{
				stack_rr(stack_a, stack_b);
				stack_b->array[fstst_i].score_b--;
				stack_b->array[fstst_i].score_a--;
			}
			else if (stack_b->array[fstst_i].is_reversed_a && \
				stack_b->array[fstst_i].is_reversed_b)
			{
				stack_rrr(stack_a, stack_b);
				stack_b->array[fstst_i].score_b--;
				stack_b->array[fstst_i].score_a--;
			}
		}
		else
		{
			if (stack_b->array[fstst_i].score_b > 0)
			{
				if (!stack_b->array[fstst_i].is_reversed_b)
					stack_rb(stack_b);
				else
					stack_rrb(stack_b);
				stack_b->array[fstst_i].score_b--;
			}
			if (stack_)
		}
	}
}

static int	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	fastest_index;
	ssize_t	index;
	ssize_t	instruction

	fastest_index = 0;
	index = stack_b->top_index;
	while (index >= 0)
		if (stack_b->array[index].score < stack_b->array[fastest_index].score)
			fastest_index = index;
	while (stack_b->array[fastest_index].score_a > 0 && \
		stack_b->array[fastest_index].score_b > 0)
	{
		stack_ra()
	}
}

static int	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_specs	specials;
	ssize_t	*sorted_array;

	sorted_array = get_sorted_array(stack_a->array, stack_a->top_index + 1);
	specials = find_special_values(sorted_array, stack_a->top_index + 1);
	printf("min:	%zi, max:	%zi, mid:	%zi\n", specials.min, specials.max, specials.mid);
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
	// printf("After all:	\n");
	// printf("stack_a now:\n");
	// print_stack(stack_a);
	// printf("stack_b now:\n");
	// print_stack(stack_b);
	return (1);
}

int	full_sort(t_stack *stack_a, t_stack *stack_b)
{

	return (1);
	push_to_b(stack_a, stack_b);

	while (stack_b->top_index > -1)
	{
		clear_scores(stack_a, stack_b);
		assign_scores(stack_a, stack_b);
	}
}
