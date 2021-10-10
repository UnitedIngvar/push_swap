#include "unit_tests.h"

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_a->array = malloc(sizeof(t_scored) * 5);
	stack_a->array[0].value = 4636;
	stack_a->array[1].value = -346263;
	stack_a->array[2].value = -45634;
	stack_a->array[3].value = 5438;
	stack_a->array[4].value = 876;
	stack_a->top_index = 4;
	stack_a->length = 5;

	stack_b = malloc(sizeof(t_stack));
	stack_b->array = malloc(sizeof(ssize_t) * 5);
	stack_b->top_index = -1;
	stack_b->length = 5;

	print_stack(stack_a);
	mini_sort(stack_a, stack_b);
	print_stack(stack_a);
}
