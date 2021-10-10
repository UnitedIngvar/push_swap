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
	printf("After all:	\n");
	printf("stack_a now:\n");
	print_stack(stack_a);
	printf("stack_b now:\n");
	print_stack(stack_b);
	return (1);
}

int	full_sort(t_stack *stack_a, t_stack *stack_b)
{

	return (1);
}

int main(void)
{
	t_stack	*stack_a = malloc(sizeof(t_stack));
	t_stack *stack_b = malloc(sizeof(t_stack));
	int		arr_length = 10;

	stack_b->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->array = malloc(sizeof(t_scored) * arr_length);
	stack_a->length = arr_length;
	stack_b->length = arr_length;
	stack_a->top_index = arr_length - 1;
	stack_b->top_index = -1;

	stack_a->array[0].value = INT_MIN;
	stack_a->array[1].value = 6436;
	stack_a->array[2].value = -47;
	stack_a->array[3].value = 8;
	stack_a->array[4].value = 4;
	stack_a->array[5].value = INT_MAX;
	stack_a->array[6].value = 979;
	stack_a->array[7].value = 77;
	stack_a->array[8].value = 10;
	stack_a->array[9].value = 6447;
	stack_a->head = stack_a->array[9];
	push_to_b(stack_a, stack_b);
}
