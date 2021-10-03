#include "../push_swap.h"

ssize_t *sort_array(ssize_t *array)
{

}

bool is_sorted(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->top_index)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (false);
		i++;
	}
	return (true);
}
