#include "sort.h"

static ssize_t	*copy_array(ssize_t *arr, long len)
{
	ssize_t	*new_arr;
	int		i;

	new_arr = malloc(sizeof(ssize_t) * len);
	i = -1;
	while (++i < len)
		new_arr[i] = arr[i];
	return (new_arr);
}

ssize_t	*get_sorted_array(ssize_t *array, long len)
{
	ssize_t	*sorted_array;

	sorted_array = copy_array(array, len);
	quick_sort(sorted_array, 0, len - 1);
	return (sorted_array);
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top_index)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (false);
		i++;
	}
	return (true);
}
