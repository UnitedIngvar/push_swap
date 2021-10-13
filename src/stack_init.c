#include "push_swap.h"

t_stack *init_stack_b(int64_t length)
{
	t_stack *stack_b;
	int64_t	index;

	stack_b = malloc(sizeof(t_stack));
	stack_b->array = malloc(sizeof(t_scored) * length);
	stack_b->top_index = -1;
	index = 0;
	while (index < length)
	{
		stack_b->array[index].value = 0;
		stack_b->array[index].score_a = 0;
		stack_b->array[index].score_b = 0;
		stack_b->array[index].score = 0;
		stack_b->array[index].is_reversed_a = FALSE;
		stack_b->array[index].is_reversed_b = FALSE;
		index++;
	}
}

t_stack	*init_stack_a(int64_t *values, int64_t length)
{
	t_stack	*stack_a;
	int64_t	index;

	stack_a = malloc(sizeof(t_stack));
	stack_a->array = malloc(sizeof(t_scored) * length);
	index = 0;
	while (index < length)
	{
		stack_a->array[index].value = values[index];
		stack_a->array[index].score_a = 0;
		stack_a->array[index].score_b = 0;
		stack_a->array[index].score = 0;
		stack_a->array[index].is_reversed_a = FALSE;
		stack_a->array[index].is_reversed_b = FALSE;
		index++;
	}
	stack_a->top_index = length - 1;
	stack_a->length = length;
	stack_a->head = stack_a->array[length - 1];
}
