#include "sort.h"
#include <stdio.h>

static ssize_t	*copy_array(t_scored *arr, long len)
{
	ssize_t	*new_arr;
	int		i;

	new_arr = malloc(sizeof(ssize_t) * len);
	i = -1;
	while (++i < len)
		new_arr[i] = arr[i].value;
	return (new_arr);
}

ssize_t	*get_sorted_array(t_scored *array, long len)
{
	ssize_t	*sorted_array;

	sorted_array = copy_array(array, len);
	quick_sort(sorted_array, 0, len - 1);
	return (sorted_array);
}

t_bool	is_sorted(const t_stack *stack)
{
	int	i;

	i = stack->top_index;
	while (i > 0)
	{
		if (stack->array[i].value > stack->array[i - 1].value)
			return (FALSE);
		i--;
	}
	return (TRUE);
}

//Passs array and its len to find min, max and mid
t_specs	find_specs(const ssize_t *sorted_array, ssize_t len)
{
	t_specs	specs;

	//TODO: invent something to prevent errors of too small array.
	specs.min = sorted_array[0];
	specs.max = sorted_array[len - 1];
	specs.mid = sorted_array[len / 2];
	return (specs);
}

// int main(void)
// {
// 	int		arr_length = 10;
// 	ssize_t	*array;
// 	array = malloc(sizeof(int) * arr_length);
// 	array[0] = 0;
// 	array[1] = 1;
// 	array[2] = 2;
// 	array[3] = 3;
// 	array[4] = 4;
// 	array[5] = 5;
// 	array[6] = 6;
// 	array[7] = 7;
// 	array[8] = 8;
// 	array[9] = 9;
// 	t_specs specs = find_specs(array, arr_length);
// 	printf("min:	%zi\nmax:	%zi\nmid:	%zi", specs.min, specs.max, specs.mid);
// }
