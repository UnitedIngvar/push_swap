#include "sort.h"
#include <stdio.h>
#include <limits.h>

static int	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_specs	specials;

	specials = find_specs(stack_a->array, stack_a->length);
	while (stack_a->top_index > -1)
	{
		if (stack_a->head.value > specials.mid)
		{

		}
	}
}

int full_sort(t_stack *stack_a, t_stack *stack_b)
{

}
