#include "sort.h"

int sort_stack(t_stack *stack_a, t_stack *stack_b, int64_t length)
{
	if (length <= MINISORT_MAX_STACK_SIZE)
		mini_sort(stack_a, stack_b);
	else
		full_sort(stack_a, stack_b);
}
